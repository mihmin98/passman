#include "ListMenu.hpp"

ListMenu::ListMenu(MenuContext *context)
{
    this->Run(context);
}

void ListMenu::Run(MenuContext *context)
{
    this->context = context;
    std::string input;

    while (true)
    {
        this->itemsToDisplay = SessionInfo::GetInstance()->GetLoginInfoVector();
        this->ClearScreen();
        this->DisplayMenu();
        std::getline(std::cin, input);
        this->ParseInput(input);
    }
}

bool ListMenu::ParseInput(std::string input)
{
    //valid options:
    // num -> view item
    // delete num -> delete item

    std::vector<std::string> splitInput = this->SplitString(input, ' ');

    if (this->IsNumber(splitInput[0]))
    {
        // view item
        //TODO: chenge context to viewitem
    }
    else if (splitInput[0] == "delete" && this->IsNumber(splitInput[1]))
    {
        // delete item
    }
    else
    {
        std::cout << "\nInvalid command";
    }

    std::cin.get();
    return true;
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

bool ListMenu::IsNumber(std::string str)
{
    for (int i = 0; i < str.length(); i++)
        if (!std::isdigit(str[i]))
            return false;

    return true;
}