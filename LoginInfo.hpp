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
    void setPlatform(std::string platform, bool calcLength = true);
    void setUsername(std::string username, bool calcLength = true);
    void setPassword(std::string password, bool calcLength = true);
    void setExtraInfo(std::string extraInfo, bool calcLength = true);

    // Getters
    std::string getPlatform();
    std::string getUsername();
    std::string getPassword();
    std::string getExtraInfo();

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