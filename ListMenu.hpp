#ifndef _LIST_MENU_HPP_
#define _LIST_MENU_HPP_

#pragma once
#include "Menu.hpp"
#include "MenuContext.hpp"
#include "MainMenu.hpp"
#include "ViewMenu.hpp"
#include <cctype>

class ListMenu : public Menu
{
public:
    ListMenu(MenuContext *context);
    void Run(MenuContext *context) override;
    bool ParseInput(std::string input) override;

private:
    MenuContext *context;
    std::vector<LoginInfo *> itemsToDisplay;

    std::vector<std::string> SplitString(std::string str, char delim);
    bool IsNumber(std::string str);     
    void DisplayMenu();
    //std::string AddRightPadding(std::string str, int num, char padChar);
    void AddRightPadding(std::string &str, long unsigned int num, char padChar);
};

#endif