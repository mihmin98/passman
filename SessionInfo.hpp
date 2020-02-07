#ifndef _SESSION_INFO_HPP_
#define _SESSION_INFO_HPP_

#pragma once
#include <string>
#include <vector>
#include "LoginInfo.hpp"

class SessionInfo
{
public:
    enum SessionStage
    {
        BEFORE_DECRYPTION, // The stage before opening the file and decrypting it
        AFTER_DECRYPTION   // The stage after decrypting the file, when you have access to the LoginInfo entries
    };

    static SessionInfo *GetInstance();

    // Setters
    void SetSessionStage(SessionStage sessionStage);
    void SetUsername(std::string username);
    void SetKey(std::string key);
    void SetUnsavedChanges(bool unsavedChanges);
    void SetLoginInfoVector(std::vector<LoginInfo> &v);

    // Getters
    SessionStage GetSessionStage();
    std::string GetUsername();
    std::string GetKey();
    bool GetUnsavedChanges();
    std::string GetFilename();
    std::vector<LoginInfo *> GetLoginInfoVector();

    // Changes to the LoginInfo vector must be done with these methods

    void AddLoginInfoVector(LoginInfo toAdd);
    void AddLoginInfoVector(LoginInfo *toAdd);
    void RemoveLoginInfoVector(LoginInfo toRemove);
    void RemoveLoginInfoVector(LoginInfo *toRemove);
    void ClearLoginInfoVector();

private:
    static SessionInfo *instance;
    SessionStage sessionStage;
    std::string username;
    std::string key;
    bool unsavedChanges;
    std::vector<LoginInfo *> loginInfoVector;

    SessionInfo(); // private constructor
};

#endif