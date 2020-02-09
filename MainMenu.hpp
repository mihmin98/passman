#ifndef _MAIN_MENU_HPP_
#define _MAIN_MENU_HPP_

#pragma once
#include "Menu.hpp"
#include "MenuContext.hpp"
#include "SessionInfo.hpp"
#include "AddMenu.hpp"
#include "ListMenu.hpp"
#include "SettingsMenu.hpp"
#include "Crypto.hpp"
#include <cstdint>
#include <experimental/filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

class MainMenu : public Menu
{
public:
    MainMenu(MenuContext *context);
    void Run(MenuContext *context) override;
    bool ParseInput(std::string input) override;

private:
    void DisplayMenu();
    std::vector<std::string> SplitString(std::string str, char delim);
    void DisplayHelp();
    bool Save();

    MenuContext *context;
};

#endif