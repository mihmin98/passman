#ifndef _MENU_HPP_
#define _MENU_HPP_

#pragma once
#include <string>
#include <iostream>
#include <limits>

class MenuContext;

class Menu
{
public:
    void ClearScreen();

    virtual ~Menu();
    virtual void Run(MenuContext *context) = 0;
    virtual bool ParseInput(std::string input) = 0;
};

#endif