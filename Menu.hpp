#ifndef _MENU_HPP_
#define _MENU_HPP_

#pragma once
#include <string>
#include <iostream>
class Menu
{
public:
    enum MenuState
    {
        START_MENU, // When you have to select if you want to create or open file
        MAIN_MENU,  // Main menu after file decryption
        LIST_ITEMS, // Menu when you list LoginInfo items
        VIEW_ITEM,  // Menu where you view a specific menu entry
        SETTINGS    // Menu where you change filename or key
    };

    MenuState GetMenuState();
    void SetMenuState(MenuState menuState);
    void ClearScreen();

    virtual void run(MenuContext *context) = 0;
    virtual void ParseInput(std::string input) = 0;
private:
    MenuState menuState;
};

class MenuContext
{
public:
    MenuContext();
    void SetState(Menu *state);

private:
    Menu *state;
};
#endif