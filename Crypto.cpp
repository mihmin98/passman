#include "Crypto.hpp"
#include <memory>

std::uint8_t *Crypto::Encrypt(std::vector<LoginInfo> &v, std::string key)
{
    std::uintmax_t size = 0;
    // For each element we add a uint16_t that specifies the length in bytes of the encrypted element and the size of a sha256 hash
    size += v.size() * (sizeof(uint16_t) + SHA256_BLOCK_SIZE);

    for (std::vector<LoginInfo>::iterator it = v.begin(); it != v.end(); std::advance(it, 1))
        size += it->GetSize();

    // Even if the data fits exactly, we should add another block that is made full of padding bytes
    std::uint8_t padSize = AES_BLOCKLEN;
    if (size % AES_BLOCKLEN != 0)
        padSize = AES_BLOCKLEN - (size % AES_BLOCKLEN);

    std::uint8_t *data = new uint8_t[size + padSize];
    std::uint8_t *p = data;

    // Serialize elements and copy/move them
    for (std::vector<LoginInfo>::iterator it = v.begin(); it != v.end(); std::advance(it, 1))
    {
        std::uint16_t elementSize = it->GetSize();
        std::memcpy(p, &elementSize, sizeof(uint16_t));
        p += sizeof(uint16_t);

        std::uint8_t *serializedElement = it->Serialize();

        // Create SHA256 hash for the serialized element
        std::uint8_t *sha256Hash = Crypto::HashData(serializedElement, elementSize);

        // Move hash
        std::memmove(p, sha256Hash, SHA256_BLOCK_SIZE);
        p += SHA256_BLOCK_SIZE;

        // Move serialized data
        std::memmove(p, serializedElement, elementSize);
        p += elementSize;
    }

    // Add padding
    Crypto::AddPadding(data + size, data + size + padSize);

    // Create key hash
    std::uint8_t *keyHash = Crypto::HashKey(key);

    // Encrypt the data
    AES_ctx aes_ctx;
    std::uint8_t iv[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    AES_init_ctx_iv(&aes_ctx, keyHash, iv);
    AES_CBC_encrypt_buffer(&aes_ctx, data, size + padSize);

    delete[] keyHash;

    return data;
}

// Decrypts the data, may throw exception
std::vector<LoginInfo> Crypto::Decrypt(std::uint8_t *data, std::uintmax_t size, std::string key)
{
    // Get key hash
    std::uint8_t *keyHash = Crypto::HashKey(key);

    // Decrypt the data
    AES_ctx aes_ctx;
    std::uint8_t iv[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    AES_init_ctx_iv(&aes_ctx, keyHash, iv);
    AES_CBC_decrypt_buffer(&aes_ctx, data, size);

    // Delete the key hash, we don't need it anymore
    delete[] keyHash;

    // Find out where the real data ends
    std::uint8_t padSize = data[size - 1];
    std::uint8_t *dataEnd = data + (size - padSize); // dataEnd is where the padding starts

    std::uint8_t *p = data;
    std::vector<LoginInfo> v;

    // Add each element to the vector
    while (p < dataEnd)
    {
        std::uint16_t *elementSize = (std::uint16_t *)((void *)p); // I don't know if there is a better way to do this, maybe static_cast ??
        p += sizeof(std::uint16_t);

        // Hash 1 is the hash stored in the file
        std::uint8_t *sha256Hash1 = p;
        p += SHA256_BLOCK_SIZE;

        std::uint8_t *elementData = p;

        // Hash 2 is the hash calculated after decryption to check data integrity
        std::uint8_t *sha256Hash2 = Crypto::HashData(elementData, *elementSize);

        // if the hashes are not equal, throw
        if (std::memcmp(sha256Hash1, sha256Hash2, SHA256_BLOCK_SIZE))
            throw 1;

        v.push_back(LoginInfo(elementData));
    }

    return v;
}

// TODO: Maybe remove HashKey; it's useless considering we have HashData(), or maybe leave it as a function wrapper
std::uint8_t *Crypto::HashKey(std::string key)
{
    std::unique_ptr<std::uint8_t[]> keyBuf(new uint8_t[key.length()]);
    return Crypto::HashData(keyBuf.get(), key.length());
}

std::uint8_t *Crypto::HashData(std::uint8_t *data, std::size_t size)
{
    SHA256_CTX ctx;
    std::uint8_t *hash = new std::uint8_t[SHA256_BLOCK_SIZE];

    sha256_init(&ctx);
    sha256_update(&ctx, data, size);
    sha256_final(&ctx, hash);

    return hash;
}

// Adds PKCS#7 padding from start to end
void Crypto::AddPadding(std::uint8_t *start, std::uint8_t *end)
{
    std::uint8_t pad = end - start;
    std::uint8_t *p = start;
    while (p <= end)
    {
        *p = pad;
        p++;
    }
}
