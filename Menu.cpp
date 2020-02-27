#include "Menu.hpp"

// For clearing screen in Windows we will use system("cls")
#ifdef _WIN32
#include <cstdlib>
#endif

void ClearScreen()
{
#if defined(__linux__)
    std::cout << "\033[2J\033[1;1H";
#elif defined(_WIN32)
    std::system("cls");
#endif
}