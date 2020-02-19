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

void ListMenu::DisplayMenu()
{
    // Get max length for each column
    // I think I won't display extra info in this menu
    int maxPlatform = 0, maxUsername = 0, maxPassword = 0;

    

    std::cout << "\t\tPassMan\n\n";
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
        // TODO: chenge context to viewitem
    }
    else if (splitInput[0] == "delete" && this->IsNumber(splitInput[1]))
    {
        // delete item
        // the numbers are displayed from 1..n
        int num = std::stoi(splitInput[1]);
        if (num > 0 && num <= this->itemsToDisplay.size())
        {
            num--;
            SessionInfo *session = SessionInfo::GetInstance();
            LoginInfo *toDelete = itemsToDisplay[num];
            session->RemoveLoginInfoVector(toDelete);
        }
        else
        {
            std::cout << "Invalid input\n";
        }
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