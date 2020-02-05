#ifndef _CRYPTO_HPP_
#define _CRYPTO_HPP_

#pragma once
#include <cstring>
#include <cstdint>
#include <string>
#include <vector>
#include "LoginInfo.hpp"
#include "aes/aes.hpp"
#include "sha256/sha256.hpp"

class Crypto
{
public:
    static std::uint8_t *Encrypt(std::vector<LoginInfo> v, std::string key);
    static std::vector<LoginInfo> Decrpyt(std::uint8_t *data, std::uint32_t size, std::string key);
private:
    static std::uint8_t *HashKey(std::string key);
    static void AddPadding(std::uint8_t *start, std::uint8_t *end);
};

#endif