#include "StartMenu.hpp"

namespace fs = std::experimental::filesystem;

StartMenu::StartMenu(MenuContext *context)
{
    this->Run(context);
}

void StartMenu::Run(MenuContext *context)
{
    // while in this state
    // Clear screen
    // Display screen
    // Get Input
    // Parse Input
    // If input is valid run the according functions
    // If all is ok and can proceed to the next state, exit the loop and change state
    // If somethin is bad restart loop

    std::string input;
    while (true)
    {
        Menu::ClearScreen();
        this->DisplayMenu();
        std::getline(std::cin, input);
        if (ParseInput(input))
        {
            break;
        }
    }

    context->SetState(new MainMenu(context));
    delete this;
}

bool StartMenu::ParseInput(std::string input)
{
    // Valid inputs: 1, 2
    if (input == "1")
        return this->NewFile();
    else if (input == "2")
        return this->OpenFile();
    else
        return false;
}

bool StartMenu::NewFile()
{
    std::cout << "\n\n Enter profile name\n\n> ";
    std::string profileName;
    std::getline(std::cin, profileName);

    std::string filename = profileName + ".passdat";
    fs::path filePath = fs::current_path() / filename;

    // Check if file already exists
    bool canCreateFile = true;

    if (fs::exists(filePath))
    {
        std::cout << "\n There is a file with the same name.\n Overwrite? (y/n)\n> ";
        std::string input;
        std::getline(std::cin, input);
        if (input[0] == 'y' || input[0] == 'Y')
        {
            canCreateFile = true;
        }
        else if (input[0] == 'n' || input[0] == 'N')
        {
            canCreateFile = false;
        }
        else
        {
            std::cout << "\n Invalid input";
            std::cin.get();
            return false;
        }
    }

    if (!canCreateFile)
    {
        std::cout << "\n Could not create file";
        std::cin.get();
        return false;
    }

    // Try to create file
    if (!this->CreateFile(filePath))
    {
        std::cout << "Failed to create file";
        std::cin.get();
        return false;
    }

    // Get key
    std::cout << "\n\n Enter the key\n >";
    std::string key;
    std::getline(std::cin, key);

    // If success set sessioninfo variables and return true
    SessionInfo *session = SessionInfo::GetInstance();
    session->SetUsername(profileName);
    session->SetKey(key);
    session->ClearLoginInfoVector();
    session->SetUnsavedChanges(false);

    return true;
}

bool StartMenu::OpenFile()
{
    // Get list of files that have .passdat extension
    std::vector<fs::path> validFiles = this->GetListOfFiles();

    // If there are no valid files, return false
    if (validFiles.size() == 0)
    {
        std::cout << "No files in folder";
        std::cin.get();
        return false;
    }

    // make user select one of them by index number
    for (int i = 0; i < validFiles.size(); i++)
        std::cout << i + 1 << ". " << validFiles[i].filename() << "\n";

    std::cout << "\n> ";

    int fileIndex;

    std::cin >> fileIndex;
    while (fileIndex < 1 && fileIndex > validFiles.size())
    {
        std::cout << "Invalid input\n> ";
        std::cin >> fileIndex;
    }
    fileIndex--;

    // ask for key
    std::string key;
    std::cout << "Enter key: ";
    std::cin >> key;

    // read data from file
    std::uintmax_t fileSize = fs::file_size(validFiles[fileIndex]);
    std::uint8_t *data = new std::uint8_t[fileSize];
    std::fstream f(validFiles[fileIndex].filename(), std::fstream::in);
    f.read((char *)data, fileSize);
    f.close();

    // try to decrypt
    std::vector<LoginInfo> decryptedLoginInfo;
    try
    {
        decryptedLoginInfo = Crypto::Decrypt(data, fileSize, key);
    }
    catch (int e)
    {
        if (e == 10)
            std::cout << "Hashes are not equal\n";
        return false;
    }

    // if ok set session info and return true
    SessionInfo *session = SessionInfo::GetInstance();
    std::string username = validFiles[fileIndex].filename();
    username.erase(username.length() - 8);
    session->SetUsername(username);
    session->SetKey(key);
    session->SetLoginInfoVector(decryptedLoginInfo);
    session->SetUnsavedChanges(false);

    return true;
}

void StartMenu::DisplayMenu()
{
    std::cout << "\t\tPassMan"
              << "\n\n"
              << " 1. Create new file\n 2. Open file\n\n> ";
}

bool StartMenu::CreateFile(fs::path path)
{
    std::fstream f(path.filename(), std::fstream::out | std::fstream::trunc);

    if (f.good())
    {
        f.close();
        return true;
    }

    return false;
}

bool StartMenu::CreateFile(std::string path)
{
    std::fstream f(path, std::fstream::out | std::fstream::trunc);

    if ((f.rdstate() & std::fstream::goodbit) != 0)
    {
        f.close();
        return true;
    }

    return false;
}

std::vector<fs::path> StartMenu::GetListOfFiles()
{
    std::vector<fs::path> validFiles;

    for (auto &it : fs::directory_iterator(fs::current_path()))
        if (it.path().extension() == ".passdat")
            validFiles.push_back(it.path());

    return validFiles;
}