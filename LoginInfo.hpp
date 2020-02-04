#ifndef _LOGIN_INFO_HPP_
#define _LOGIN_INFO_HPP_

#pragma once
#include <cstdint>
#include <string>

class LoginInfo
{
public:
    LoginInfo();
    LoginInfo(std::string platform, std::string username, std::string password, std::string extraInfo);

    // Setters
    void SetPlatform(std::string platform, bool calcLength = true);
    void SetUsername(std::string username, bool calcLength = true);
    void SetPassword(std::string password, bool calcLength = true);
    void SetExtraInfo(std::string extraInfo, bool calcLength = true);

    // Getters
    std::string GetPlatform();
    std::string GetUsername();
    std::string GetPassword();
    std::string GetExtraInfo();
    std::uint16_t GetPlatformLength();
    std::uint16_t GetUsernameLength();
    std::uint16_t GetPasswordLength();
    std::uint16_t GetExtraInfoLength();

private:
    std::string platform;
    std::string username;
    std::string password;
    std::string extraInfo;

    std::uint16_t platformLength;
    std::uint16_t usernameLength;
    std::uint16_t passwordLength;
    std::uint16_t extraInfoLength;
};

#endif