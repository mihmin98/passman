#include "ViewMenu.hpp"

ViewMenu::ViewMenu(MenuContext *context, LoginInfo *item)
{
    this->context = context;
    this->currentItem = item;

    this->Run(context);
}

void ViewMenu::Run(MenuContext *context)
{
    std::string input;

    while(true)
    {
        this->ClearScreen();
        this->DisplayItem();
        std::getline(std::cin, input);
        this->ParseInput(input);
    }
}

bool ViewMenu::ParseInput(std::string input)
{
    if (input == "edit" || input == "e") {
        EditItem();
    }
    else if (input == "delete" || input == "remove") {
        std::cout << "n\Are you sure you want to delete this item? (Y/n)\n> ";
        std::cin >> input;
        if (input[0] == 'Y' || input[0] == 'y') 
        {
            RemoveItem();
            // Change state to ListMenu
            this->context->SetState(new ListMenu(this->context));
            delete this;
        }
    }
    else if (input[0] == 'q') {
        this->context->SetState(new ListMenu(this->context));
        delete this;
    }
    else {
        std::cout << "Invalid Input\n";
    }

    std::cin.get();
    return true;
}

void ViewMenu::DisplayItem()
{
    std::cout << "\t\tPassman\n\nPlatform: " << currentItem->GetPlatform() << "\nUsername: "
              << currentItem->GetUsername() << "\nPassword: " << currentItem->GetPassword()
              << "\nExtra Info: " << currentItem->GetExtraInfo() << "\n\n> ";
}

void ViewMenu::EditItem()
{
    std::string platform, username, password, extraInfo;
    
    // Platform 
    std::cout << "\nEnter new platfrom name (Leave empty to keep)\n> ";
    std::getline(std::cin, platform);

    // Username
    std::cout << "\nEnter new username (Leave empty to keep)\n> ";
    std::getline(std::cin, username);

    // Password 
    std::cout << "\nEnter new password (Leave empty to keep)\n> ";
    std::getline(std::cin, password);

    // ExtraInfo 
    std::cout << "\nEnter new extra info (Leave empty to keep)\n> ";
    std::getline(std::cin, extraInfo);

    if (!(platform == "" || platform  == "\n")) {
        currentItem->SetPlatform(platform);
    }

    if (!(username == "" || username  == "\n")) {
        currentItem->SetUsername(username);
    }

    if (!(password == "" || password  == "\n")) {
        currentItem->SetPassword(password);
    }

    if (!(extraInfo == "" || extraInfo  == "\n")) {
        currentItem->SetExtraInfo(extraInfo);
    }
}

void ViewMenu::RemoveItem()
{
    SessionInfo::GetInstance()->RemoveLoginInfoVector(currentItem);
}