#ifndef _START_MENU_HPP_
#define _START_MENU_HPP_

#pragma once
#include "Menu.hpp"
#include "MenuContext.hpp"
#include "SessionInfo.hpp"
#include "Crypto.hpp"
#include <iostream>
#include <experimental/filesystem>
#include <fstream>
#include <cstdint>

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
};

#endif