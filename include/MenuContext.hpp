#ifndef _MENU_CONTEXT_HPP_
#define _MENU_CONTEXT_HPP_

#pragma once
#include "StartMenu.hpp"

class Menu;

class MenuContext
{
public:
    MenuContext();
    void SetState(Menu *state);

private:
    Menu *state;
};

#endif