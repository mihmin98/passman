#ifndef _MENU_CONTEXT_HPP_
#define _MENU_CONTEXT_HPP_

#pragma once
#include "Menu.hpp"
#include "StartMenu.hpp"

class MenuContext
{
public:
    MenuContext();
    void SetState(Menu *state);

private:
    Menu *state;
};

#endif