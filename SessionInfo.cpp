#include "SessionInfo.hpp"

SessionInfo *SessionInfo::instance = 0;

SessionInfo::SessionInfo()
{
    this->username = "";
    this->key = "";
    this->unsavedChanges = false;
}

SessionInfo *SessionInfo::GetInstance()
{
    if (!instance)
        instance = new SessionInfo();

    return instance;
}

void SessionInfo::SetUsername(std::string username)
{
    this->username = username;
}

void SessionInfo::SetKey(std::string key)
{
    this->key = key;
}

void SessionInfo::SetUnsavedChanges(bool unsavedChanges)
{
    this->unsavedChanges = unsavedChanges;
}

std::string SessionInfo::GetUsername()
{
    return this->username;
}

std::string SessionInfo::GetKey()
{
    return this->key;
}

bool SessionInfo::GetUnsavedChanges()
{
    return this->unsavedChanges;
}

std::string SessionInfo::GetFilename()
{
    return this->username + ".passdat";
}