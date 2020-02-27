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
#if defined(__linux__)
    std::cout << "\033[2J\033[1;1H";
#elif defined(_WIN32)
    std::system("cls");
#endif
}

void Menu::FlushInputStream(std::istream &stream)
{
    stream.clear();
    stream.ignore(std::numeric_limits<std::streamsize>::max());
}