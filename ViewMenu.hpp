#ifndef _VIEW_MENU_HPP_
#define _VIEW_MENU_HPP_

#pragma once
#include "Menu.hpp"
#include "MenuContext.hpp"
#include "ListMenu.hpp"
#include "LoginInfo.hpp"

class ViewMenu : public Menu
{
public:
    ViewMenu(MenuContext *context, LoginInfo *item);
    void Run(MenuContext *context) override;
    bool ParseInput(std::string input) override;

    void DisplayItem();
    void EditItem();
    void RemoveItem();
private:
    MenuContext *context;
    LoginInfo *currentItem;
};

#endif