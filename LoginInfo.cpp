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