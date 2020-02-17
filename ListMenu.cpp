#include "ListMenu.hpp"

ListMenu::ListMenu(MenuContext *context)
{
    this->Run(context);
}

void ListMenu::Run(MenuContext *context)
{
    this->context = context;
    std::string input;

    this->itemsToDisplay = SessionInfo::GetInstance()->GetLoginInfoVector();

    while (true)
    {
        this->ClearScreen();
        this->DisplayMenu();
    }
}

bool ListMenu::ParseInput(std::string input)
{
}

std::vector<std::string> SplitString(std::string str, char delim)
{
    std::vector<std::string> split;
    std::string x;
    std::istringstream s(str);

    while (std::getline(s, x, delim))
        split.push_back(x);

    return split;
}