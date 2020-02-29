#include "MainMenu.hpp"

namespace fs = std::experimental::filesystem;

MainMenu::MainMenu(MenuContext *context)
{
    this->Run(context);
}

void MainMenu::Run(MenuContext *context)
{
    // while in this state
    // Clear screen
    // Display screen
    // Get Input
    // Parse Input
    // If input is valid run the according functions
    // If somethin is bad restart loop
    this->context = context;
    std::string input;
    while (true)
    {
        this->ClearScreen();
        this->DisplayMenu();
        std::getline(std::cin, input);
        ParseInput(input);
    }
}

bool MainMenu::ParseInput(std::string input)
{
    // Split the input into words
    std::vector<std::string> splitInput = this->SplitString(input, ' ');

    if (input == "" || input == "\n") {
        // If input is empty, do notihng
        return true;
    }

    // The first word selects the action
    // TODO: Maybe add search here
    if (splitInput[0] == "add")
    {
        // Change state to AddMenu
        this->context->SetState(new AddMenu(context));
        delete this;
    }
    else if (splitInput[0] == "list")
    {
        // Change state to ListMenu
        this->context->SetState(new ListMenu(context));
        delete this;
    }
    else if (splitInput[0] == "help")
    {
        DisplayHelp();
    }
    else if (splitInput[0] == "settings")
    {
        // Change state to SettingsMenu
        this->context->SetState(new SettingsMenu(context));
        delete this;
    }
    else if (splitInput[0] == "save")
    {
        bool save = this->Save();
        if (save)
            std::cout << "Save successful\n";
        else
            std::cout << "Save failed\n";

    }
    else if (splitInput[0] == "exit")
    {
        bool canExit = true;
        if (SessionInfo::GetInstance()->GetUnsavedChanges())
        {
            std::cout << "There are unsaved changes. Are you sure you want to quit? (Y/n)\n> ";
            std::string choice;
            std::getline(std::cin, choice);
            if (choice[0] != 'y' && choice[0] != 'Y')
                canExit = false;
        }

        if (canExit)
            // Goodbye cruel world, it's over
            std::exit(0);
    }
    else
    {
        std::cout << "\nInvalid command";
    }

    std::cin.get();

    // I don't think the return value is actually used here
    return true;
}

void MainMenu::DisplayMenu()
{
    SessionInfo *session = SessionInfo::GetInstance();

    std::cout << "\t\tPassMan\n\n";
    if (session->GetUnsavedChanges())
        std::cout << "You have unsaved changes\n\n";

    std::cout << "Type \"help\" for commands\n\n> ";
}

std::vector<std::string> MainMenu::SplitString(std::string str, char delim)
{
    std::vector<std::string> split;
    std::string x;
    std::istringstream s(str);

    while (std::getline(s, x, delim))
        split.push_back(x);

    return split;
}

// Displays help page
void MainMenu::DisplayHelp()
{
    this->ClearScreen();

    std::cout << "\t\tHelp\n\n"
              << "add - Adds a new entry\n"
              << "list - Lists all entries\n"
              << "search - While in list mode, searches by Platform and Username\n"
              << "sort - While in list mode, sorts the entries by a column, ASC or DESC\n"
              << "help - Displays this menu\n"
              << "settings - Shows the settings menu\n"
              << "save - Writes the changes to the file, if there are any\n"
              << "exit - exit\n";
}

bool MainMenu::Save()
{
    SessionInfo *session = SessionInfo::GetInstance();
    if (session->GetUnsavedChanges() == false)
    {
        std::cout << "There are no changes to save\n";
        return false;
    }

    // Create backup file
    std::string filename = session->GetFilename();
    fs::path filePath = fs::current_path() / filename;

    //date string format: yyyymmdd_hhmmss
    std::time_t t = std::time(nullptr);
    char dateText[16];
    std::strftime(dateText, 15, "%Y%m%d_%H%M%S", std::localtime(&t));
    std::string dateString(dateText);
    std::string backupFilename = session->GetUsername() + "-" + dateString + ".passdat";

    // Copy file
    fs::path backupPath = fs::current_path() / backupFilename;
    fs::copy(filePath, backupPath);

    // Get serialized string
    std::vector<LoginInfo> loginInfoCopy = session->GetLoginInfoVectorCopy();
    std::uintmax_t dataSize;
    std::uint8_t *encryptedData = Crypto::Encrypt(loginInfoCopy, session->GetKey(), dataSize);

    // Overwrite file
    std::fstream f(filename, std::fstream::out | std::fstream::trunc);
    f.write((char *)encryptedData, dataSize);
    f.close();

    session->SetUnsavedChanges(false);

    delete[] encryptedData;

    return true;

    // TODO: add more error checking
}