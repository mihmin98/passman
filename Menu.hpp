#ifndef _MENU_HPP_
#define _MENU_HPP_

#pragma once
#include <string>
#include <iostream>
#include <limits>
#include "Menu.fwd.hpp"
#include "MenuContext.fwd.hpp"
class Menu
{
public:
    void ClearScreen();
    void FlushInputStream(std::istream &stream);

    virtual ~Menu();
    virtual void Run(MenuContext *context) = 0;
    virtual bool ParseInput(std::string input) = 0;
};

#endif