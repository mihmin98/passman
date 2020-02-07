#include "SessionInfo.hpp"

SessionInfo *SessionInfo::instance = 0;

SessionInfo::SessionInfo()
{
    this->sessionStage = SessionStage::BEFORE_DECRYPTION;
    this->username = "";
    this->key = "";
    this->unsavedChanges = false;
    this->loginInfoVector.clear();
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

void SessionInfo::SetLoginInfoVector(std::vector<LoginInfo> &v)
{
    ClearLoginInfoVector();

    for (std::vector<LoginInfo>::iterator it = v.begin(); it != v.end(); std::advance(it, 1))
        this->loginInfoVector.push_back(new LoginInfo(*it));
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

std::vector<LoginInfo *> SessionInfo::GetLoginInfoVector()
{
    return this->loginInfoVector;
}

void SessionInfo::AddLoginInfoVector(LoginInfo toAdd)
{
    this->loginInfoVector.push_back(new LoginInfo(toAdd));
}

void SessionInfo::AddLoginInfoVector(LoginInfo *toAdd)
{
    this->loginInfoVector.push_back(toAdd);
}

void SessionInfo::RemoveLoginInfoVector(LoginInfo toRemove)
{
    for (std::vector<LoginInfo *>::iterator it = this->loginInfoVector.begin(); it != this->loginInfoVector.end(); std::advance(it, 1))
    {
        // Compare by value
        if (*(*it) == toRemove)
        {
            this->loginInfoVector.erase(it);
            break;
        }
    }
}

void SessionInfo::RemoveLoginInfoVector(LoginInfo *toRemove)
{
    for (std::vector<LoginInfo *>::iterator it = this->loginInfoVector.begin(); it != this->loginInfoVector.end(); std::advance(it, 1))
    {
        // Compare by address
        if (*it == toRemove)
        {
            this->loginInfoVector.erase(it);
            break;
        }
    }
}

void SessionInfo::ClearLoginInfoVector()
{
    this->loginInfoVector.clear();
}