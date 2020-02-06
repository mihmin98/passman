#ifndef _SESSION_INFO_HPP_
#define _SESSION_INFO_HPP_

#pragma once
#include <string>

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

    // Getters
    SessionStage GetSessionStage();
    std::string GetUsername();
    std::string GetKey();
    bool GetUnsavedChanges();
    std::string GetFilename();

private:
    static SessionInfo *instance;
    SessionStage sessionStage;
    std::string username;
    std::string key;
    bool unsavedChanges;

    SessionInfo(); // private constructor
};

#endif