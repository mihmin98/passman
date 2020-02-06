#include "Menu.hpp"

// For clearing screen in Windows we will use system("cls")
#ifdef _WIN32
#include <cstdlib>
#endif

Menu::MenuState Menu::GetMenuState()
{
    return this->menuState;
}

void Menu::SetMenuState(MenuState menuState)
{
    this->menuState = menuState;
}

void ClearScreen()
{
#if defined(__linux__)
    std::cout << "\033[2J\033[1;1H";
#elif defined(_WIN32)
    std::system("cls");
#endif
}