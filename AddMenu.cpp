#include "AddMenu.hpp"

AddMenu::AddMenu(MenuContext *context)
{
    this->Run(context);
}

void AddMenu::Run(MenuContext *context)
{
    LoginInfo *login = new LoginInfo;
    std::string input = "";

    this->ClearScreen();

    // get platform
    std::cout << "\t\tPassMan\n\tAdd new entry\n\nEnter Platfrom name: ";
    std::getline(std::cin, input);

    while (input == "")
    {
        std::cout << "Input cannot be empty\n> ";
        std::getline(std::cin, input);
    }

    login->SetPlatform(input);

    // get name
    input = "";
    std::cout << "\nEnter Username: ";
    std::getline(std::cin, input);

    while (input == "")
    {
        std::cout << "Input cannot be empty\n> ";
        std::getline(std::cin, input);
    }

    login->SetUsername(input);

    // get password
    input = "";
    std::cout << "\nEnter Password: ";
    std::getline(std::cin, input);

    while (input == "")
    {
        std::cout << "Input cannot be empty\n> ";
        std::getline(std::cin, input);
    }

    login->SetPassword(input);

    // get extra info
    input = "";
    std::cout << "\nEnter Extra Info: ";
    std::getline(std::cin, input);

    login->SetExtraInfo(input);

    // confirm to add
    std::cout << "\n"
              << login->GetString() << "\n\nAre you sure you want to add this entry? (Y/n): ";
    std::getline(std::cin, input);

    // if yes then update session info
    if (input[0] == 'y' || input[0] == 'Y')
    {
        SessionInfo *session = SessionInfo::GetInstance();
        session->AddLoginInfoVector(login);
        session->SetUnsavedChanges(true);

        std::cout << "Entry added successfully\n";
        std::cin.get();
    }

    // set state to main menu
    context->SetState(new MainMenu(context));
    delete this;
}

bool AddMenu::ParseInput(std::string input)
{
    return true;
}