#include "Menu.hpp"

// For clearing screen in Windows we will use system("cls")
#ifdef _WIN32
#include <cstdlib>
#endif

Menu::~Menu()
{
}

void Menu::ClearScreen()
{
#ifdef __linux__
    std::cout << "\033[2J\033[1;1H";
#elif _WIN32
    std::system("cls");
#endif
}
