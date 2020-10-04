#ifndef _ADD_MENU_HPP_
#define _ADD_MENU_HPP_

#pragma once
#include "Menu.hpp"
#include "MenuContext.hpp"
#include "MainMenu.hpp"
#include "SessionInfo.hpp"
#include "LoginInfo.hpp"
#include <iostream>

class AddMenu : public Menu
{
public:
    AddMenu(MenuContext *context);
    void Run(MenuContext *context) override;
    bool ParseInput(std::string input) override;
private:
};
#endif