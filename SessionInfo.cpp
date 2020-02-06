#include "SessionInfo.hpp"

SessionInfo *SessionInfo::instance = 0;

SessionInfo::SessionInfo()
{
    this->sessionStage = SessionStage::BEFORE_DECRYPTION;
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

void SessionInfo::SetSessionStage(SessionInfo::SessionStage sessionStage)
{
    this->sessionStage = sessionStage;
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

SessionInfo::SessionStage SessionInfo::GetSessionStage()
{
    return this->sessionStage;
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