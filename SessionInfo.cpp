#include "SessionInfo.hpp"

SessionInfo::SessionInfo(std::string username, std::string key)
{
    this->username = username;
    this->key = key;
}

// Setters
void SessionInfo::SetUsername(std::string username)
{
    this->username = username;
}

void SessionInfo::SetKey(std::string key)
{
    this->key = key;
}

// Getters
std::string SessionInfo::GetUsername()
{
    return this->username;
}

std::string SessionInfo::GetKey()
{
    return this->key;
}
