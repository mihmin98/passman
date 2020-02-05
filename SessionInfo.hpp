#ifndef _SESSION_INFO_HPP_
#define _SESSION_INFO_HPP_

#pragma once
#include <string>

class SessionInfo
{
public:
    SessionInfo(std::string username, std::string key);

    // Setters
    void SetUsername(std::string username);
    void SetKey(std::string key);

    // Getters
    std::string GetUsername();
    std::string GetKey();

private:
    //TODO: See if I should change these vars to be static
    std::string username;
    std::string key;
};

#endif