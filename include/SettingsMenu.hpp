#ifndef _SETTINGS_MENU_HPP_
#define _SETTINGS_MENU_HPP_

#pragma once
#include "Menu.hpp"
#include "MenuContext.hpp"
#include "MainMenu.hpp"
#include <iostream>
#include <string>

class SettingsMenu : public Menu
{
public:
    SettingsMenu(MenuContext *context);
    void Run(MenuContext *context) override;
    bool ParseInput(std::string input) override;

private:
    MenuContext *context;

    void DisplayMenu();
    void ChangeUsername();
    void ChangeKey();
};

#endif