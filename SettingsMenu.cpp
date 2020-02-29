#include "SettingsMenu.hpp"

SettingsMenu::SettingsMenu(MenuContext *context)
{
    this->Run(context);
}

void SettingsMenu::Run(MenuContext *context)
{
    this->context = context;

    // clear screen
    // show menu
    // parse input
    // do that thing
    // loop

    std::string input;
    while (true)
    {
        this->ClearScreen();
        this->DisplayMenu();
        std::getline(std::cin, input);
        this->ParseInput(input);
    }
}

bool SettingsMenu::ParseInput(std::string input)
{
    if (input == "" || input == "\n") {
        // If input is empty, do notihng
        return true;
    }

    if (input == "1")
    {
        this->ChangeUsername();
    }
    else if (input == "2")
    {
        this->ChangeKey();
    }
    else if (input == "3")
    {
        // Change state to MainMenu
        this->context->SetState(new MainMenu(this->context));
        delete this;
    }
    else
    {
        // Invalid input
        std::cout << "Invalid input\n";
        std::cout << "\nPress ENTER to continue...";
        std::cin.get();
    }

    return true;
}

void SettingsMenu::DisplayMenu()
{
    std::cout << "\t\tPassMan\n\tSettings\n\n 1. Change username\n 2. Change key\n 3. Return\n\n> ";
}

void SettingsMenu::ChangeUsername()
{
    std::string input = "";

    while (input == "")
    {
        std::cout << "\n\nEnter new username: ";
        std::getline(std::cin, input);
        if (input == "")
            std::cout << "Invalid input";
    }

    SessionInfo *session = SessionInfo::GetInstance();
    session->SetUsername(input);
    session->SetUnsavedChanges(true);
}

void SettingsMenu::ChangeKey()
{
    std::string input = "";
    SessionInfo *session = SessionInfo::GetInstance();

    std::cout << "\n\nEnter current key: ";
    std::getline(std::cin, input);
    if (input != session->GetKey())
    {
        std::cout << "Keys do not match";
        std::cout << "\nPress ENTER to continue...";
        std::cin.get();
        return;
    }

    std::string newKey1, newKey2;

    std::cout << "\n\nEnter new key: ";
    std::getline(std::cin, newKey1);

    std::cout << "\n\nRe-enter new key: ";
    std::getline(std::cin, newKey2);

    if (newKey1 != newKey2)
    {
        std::cout << "Keys do not match";
        std::cout << "\nPress ENTER to continue...";
        std::cin.get();
        return;
    }

    session->SetKey(newKey1);
    session->SetUnsavedChanges(true);
}