#ifndef _SESSION_INFO_HPP_
#define _SESSION_INFO_HPP_

#pragma once
#include <string>

class SessionInfo
{
public:
    static SessionInfo *GetInstance();

    // Setters
    void SetUsername(std::string username);
    void SetKey(std::string key);
    void SetUnsavedChanges(bool unsavedChanges);

    // Getters
    std::string GetUsername();
    std::string GetKey();
    bool GetUnsavedChanges();
    std::string GetFilename();

private:
    static SessionInfo *instance;
    std::string username;
    std::string key;
    bool unsavedChanges;

    SessionInfo(); // private constructor
};

#endif