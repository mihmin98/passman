#ifndef _START_MENU_HPP_
#define _START_MENU_HPP_

#pragma once
#include "Menu.hpp"
#include "MenuContext.hpp"
#include "SessionInfo.hpp"
#include "Crypto.hpp"
#include "MainMenu.hpp"
#include <iostream>
#include <experimental/filesystem>
#include <fstream>
#include <cstdint>

// For hiding the password input
#ifdef __linux__
#include <unistd.h>
#elif _WIN32
#include <windows.h>
#endif

namespace fs = std::experimental::filesystem;
class StartMenu : public Menu
{
public:
    StartMenu(MenuContext *context);
    void Run(MenuContext *context) override;
    bool ParseInput(std::string input) override;

private:
    // Function to get all valid files from folder
    // Function to display menu
    void DisplayMenu();
    bool NewFile();
    bool OpenFile();
    bool CreateFile(fs::path path);
    bool CreateFile(std::string path);
    std::vector<fs::path> GetListOfFiles();
    
    std::string InputPassword();
};

#endif