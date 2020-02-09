#include "LoginInfo.hpp"

LoginInfo::LoginInfo()
{
    // TODO: See if this constructor is actually required
    this->platform = "";
    this->username = "";
    this->password = "";
    this->extraInfo = "";

    this->platformLength = 1;
    this->usernameLength = 1;
    this->passwordLength = 1;
    this->extraInfoLength = 1;
}

LoginInfo::LoginInfo(std::string platform, std::string username, std::string password, std::string extraInfo)
{
    this->platform = platform;
    this->username = username;
    this->password = password;
    this->extraInfo = extraInfo;

    this->platformLength = this->platform.length() + 1;
    this->usernameLength = this->username.length() + 1;
    this->passwordLength = this->password.length() + 1;
    this->extraInfoLength = this->extraInfo.length() + 1;
}

// Deserialization constructor
LoginInfo::LoginInfo(std::uint8_t *data)
{
    std::uint8_t *p = data;

    // Platform
    this->platformLength = *((std::uint16_t *)((void *)p));
    p += sizeof(this->platformLength);

    this->platform = std::string(this->platformLength, '0');
    for (int i = 0; i < this->platformLength; i++, p++)
        this->platform[i] = *p;

    // Username
    this->usernameLength = *((std::uint16_t *)((void *)p));
    p += sizeof(this->usernameLength);

    this->username = std::string(this->usernameLength, '0');
    for (int i = 0; i < this->usernameLength; i++, p++)
        this->username[i] = *p;

    // Password
    this->passwordLength = *((std::uint16_t *)((void *)p));
    p += sizeof(this->passwordLength);

    this->password = std::string(this->passwordLength, '0');
    for (int i = 0; i < this->passwordLength; i++, p++)
        this->password[i] = *p;

    // Extra Info
    this->extraInfoLength = *((std::uint16_t *)((void *)p));
    p += sizeof(this->extraInfoLength);

    this->extraInfo = std::string(this->extraInfoLength, '0');
    for (int i = 0; i < this->extraInfoLength; i++, p++)
        this->extraInfo[i] = *p;
}

void LoginInfo::SetPlatform(std::string platform, bool calcLength = true)
{
    this->platform = platform;
    if (calcLength)
        this->platformLength = this->platform.length() + 1;
}

void LoginInfo::SetUsername(std::string username, bool calcLength = true)
{
    this->username = username;
    if (calcLength)
        this->usernameLength = this->username.length() + 1;
}

void LoginInfo::SetPassword(std::string password, bool calcLength = true)
{
    this->password = password;
    if (calcLength)
        this->passwordLength = this->password.length() + 1;
}

void LoginInfo::SetExtraInfo(std::string extraInfo, bool calcLength = true)
{
    this->extraInfo = extraInfo;
    if (calcLength)
        this->extraInfoLength = this->extraInfo.length() + 1;
}

std::string LoginInfo::GetPlatform()
{
    return this->platform;
}

std::string LoginInfo::GetUsername()
{
    return this->username;
}

std::string LoginInfo::GetPassword()
{
    return this->password;
}

std::string LoginInfo::GetExtraInfo()
{
    return this->extraInfo;
}

std::string LoginInfo::GetString()
{
    std::string s;

    s += "Platform: " + this->platform;
    s += "\nUsername: " + this->username;
    s += "\nPassword: " + this->password;
    s += "\nExtra Info: " + this->extraInfo;

    return s;
}

std::uint16_t LoginInfo::GetPlatformLength()
{
    return this->GetPlatformLength;
}

std::uint16_t LoginInfo::GetUsernameLength()
{
    return this->usernameLength;
}

std::uint16_t LoginInfo::GetPasswordLength()
{
    return this->passwordLength;
}

std::uint16_t LoginInfo::GetExtraInfoLength()
{
    return this->extraInfoLength;
}

std::uint16_t LoginInfo::GetSize()
{
    // Returns the size of all class member variables in bytes
    std::uint16_t size = 4 * sizeof(std::uint16_t); // The size of the length member variables
    size += this->platformLength + this->usernameLength + this->passwordLength + this->extraInfoLength;

    return size;
}

std::uint8_t *LoginInfo::Serialize()
{
    // Returns a pointer to the serialized string
    std::uint8_t *str = new std::uint8_t[this->GetSize()];
    std::uint8_t *p = str; // A pointer to the current location in the string

    // Platform
    std::memcpy(p, &(this->platformLength), sizeof(std::uint16_t));
    p += sizeof(std::uint16_t);
    std::memcpy(p, this->platform.c_str(), this->platformLength * sizeof(std::uint8_t));
    p += this->platformLength;

    // Username
    std::memcpy(p, &(this->usernameLength), sizeof(std::uint16_t));
    p += sizeof(std::uint16_t);
    std::memcpy(p, this->username.c_str(), this->usernameLength * sizeof(std::uint8_t));
    p += this->usernameLength;

    // Password
    std::memcpy(p, &(this->passwordLength), sizeof(std::uint16_t));
    p += sizeof(std::uint16_t);
    std::memcpy(p, this->password.c_str(), this->passwordLength * sizeof(std::uint8_t));
    p += this->passwordLength;

    // Extra Info
    std::memcpy(p, &(this->extraInfoLength), sizeof(std::uint16_t));
    p += sizeof(std::uint16_t);
    std::memcpy(p, this->extraInfo.c_str(), this->extraInfoLength * sizeof(std::uint8_t));
    p += this->extraInfoLength;

    return str;
}

bool operator==(const LoginInfo &a, const LoginInfo &b)
{
    return a.platformLength == b.platformLength && a.platform == b.platform &&
           a.usernameLength == b.usernameLength && a.username == b.username &&
           a.passwordLength == b.passwordLength && a.password == b.password &&
           a.extraInfoLength == b.extraInfoLength && a.extraInfo == b.extraInfo;
}