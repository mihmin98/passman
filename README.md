# passman
A CLI password manager written in C++

## Installing
1. Clone the repository 

`git clone https://github.com/mihmin98/passman`

2. Build the project using the Makefile 

```
cd passman
make
```

The executable will be located at `passman/build/app`

## Running
Just run the built executable `passman`

### Creating a profile
After you launch the executable, you will need to create a new user file

From the menu, select the option to create a new file and then enter a profile name and a password.

### Adding an account
From the Main Menu, type `add`

Then, type in the required info (extra info is optional), and type `Y` at the prompt for adding

You will then be returned to the Main Menu

### List accounts
From the Main Menu, type `list`

You will then be shown all of your added accounts

To exit, type `q`

### Save changes
After making changes to accounts, you will be shown in the Main Menu that you have unsaved changes

To save them, type `save`

### Help
For additional help, type `help` at the Main Menu

## License
This project is licensed under the MIT License - See [LICENSE.md](LICENSE.md) for more info

## Libraries
 * [Tiny AES by kokke](https://github.com/kokke/tiny-AES-c)
 * [SHA256 by B-Con](https://github.com/B-Con/crypto-algorithms)
