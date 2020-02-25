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
    // Get max length for each column to determine padding
    // I think I won't display extra info in this menu
    int maxPlatform = 8, maxUsername = 8, maxPassword = 8;
    for (std::vector<LoginInfo *>::iterator it = itemsToDisplay.begin(); it != itemsToDisplay.end(); std::advance(it, 1))
    {
        if ((*it)->GetPlatformLength() > maxPlatform)
            maxPlatform = (*it)->GetPlatformLength();

        if ((*it)->GetUsernameLength() > maxUsername)
            maxUsername = (*it)->GetUsernameLength();

        if ((*it)->GetPasswordLength() > maxPassword)
            maxPassword = (*it)->GetPasswordLength();
    }

    std::string displayString = "";

    // Index | Platform | Username | Password
    // First row
    std::string temp;
    temp = "Index | Platform";
    this->AddRightPadding(temp, maxPlatform, ' ');
    displayString += temp + " | ";
    temp = "Username";
    this->AddRightPadding(temp, maxUsername, ' ');
    displayString += temp + " | ";
    temp = "Password";
    this->AddRightPadding(temp, maxPassword, ' ');
    displayString += temp + "\n";

    displayString.append(maxPlatform + 3 + maxUsername + 3 + maxPassword, '-');
    displayString += "\n";


    int index = 1;
    for(std::vector<LoginInfo *>::iterator it = itemsToDisplay.begin(); it != itemsToDisplay.end(); std::advance(it, 1))
    {
        temp = std::to_string(index++) + ")";
        this->AddRightPadding(temp, 5, ' ');
        displayString += temp + " | ";

        temp = (*it)->GetPlatform();
        this->AddRightPadding(temp, maxPlatform, ' ');
        displayString += temp + " | ";

        temp = (*it)->GetUsername();
        this->AddRightPadding(temp, maxUsername, ' ');
        displayString += temp + " | ";

        temp = (*it)->GetPassword();
        this->AddRightPadding(temp, maxPassword, ' ');
        displayString += temp + "\n";
    }

    std::cout << "\t\tPassMan\n\n" << displayString << "\n> ";
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
        int index = std::stoi(splitInput[0]) - 1;
        this->context->SetState(new ViewMenu(this->context, itemsToDisplay[index]));
        delete this;
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
    else if (splitInput[0] == "exit" || splitInput[0] == "return" || splitInput[0] == "q")
    {
        this->context->SetState(new MainMenu(this->context));
        delete this;
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

/*
std::string ListMenu::AddRightPadding(std::string str, int num, char padChar)
{
    if (str.length() >= 0)
        return str;

    str.append(num - str.size(), padChar);
    return str;
}
*/

void ListMenu::AddRightPadding(std::string &str, int num, char padChar)
{
    if (str.length() >= 0)
        return;

    str.append(num - str.size(), padChar);
}