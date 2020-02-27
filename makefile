passman: main.o LoginInfo.o aes.o sha256.o Crypto.o \
		 SessionInfo.o Menu.o MenuContext.o StartMenu.o \
		 MainMenu.o SettingsMenu.o AddMenu.o ListMenu.o ViewMenu.o

	g++ -Wall -g -o passman build/main.o build/LoginInfo.o build/aes.o \
							build/sha256.o build/Crypto.o \
							build/SessionInfo.o build/Menu.o \
							build/MenuContext.o build/StartMenu.o \
							build/MainMenu.o build/SettingsMenu.o \
							build/AddMenu.o build/ListMenu.o build/ViewMenu.o \
							-lstdc++fs

main.o: main.cpp
	g++ -Wall -g -c main.cpp -o build/main.o

LoginInfo.o: LoginInfo.cpp LoginInfo.hpp
	g++ -Wall -g -c LoginInfo.cpp -o build/LoginInfo.o

aes.o: aes/aes.c aes/aes.h aes/aes.hpp
	gcc -Wall -g -c aes/aes.c -o build/aes.o

sha256.o: sha256/sha256.c sha256/sha256.h sha256/sha256.hpp
	gcc -Wall -g -c sha256/sha256.c -o build/sha256.o

Crypto.o: Crypto.cpp Crypto.hpp LoginInfo.o aes.o sha256.o
	g++ -Wall -g -c Crypto.cpp -o build/Crypto.o

SessionInfo.o: SessionInfo.cpp SessionInfo.hpp LoginInfo.o
	g++ -Wall -g -c SessionInfo.cpp -o build/SessionInfo.o

Menu.o: Menu.cpp Menu.hpp
	g++ -Wall -g -c Menu.cpp -o build/Menu.o

MenuContext.o: MenuContext.cpp MenuContext.hpp
	g++ -Wall -g -c MenuContext.cpp -o build/MenuContext.o

StartMenu.o: StartMenu.cpp StartMenu.hpp
	g++ -Wall -g -c StartMenu.cpp -o build/StartMenu.o

MainMenu.o: MainMenu.cpp MainMenu.hpp
	g++ -Wall -g -c MainMenu.cpp -o build/MainMenu.o

SettingsMenu.o: SettingsMenu.cpp SettingsMenu.hpp
	g++ -Wall -g -c SettingsMenu.cpp -o build/SettingsMenu.o

AddMenu.o: AddMenu.cpp AddMenu.hpp
	g++ -Wall -g -c AddMenu.cpp -o build/AddMenu.o

ListMenu.o: ListMenu.cpp ListMenu.hpp
	g++ -Wall -g -c ListMenu.cpp -o build/ListMenu.o

ViewMenu.o: ViewMenu.cpp ViewMenu.hpp
	g++ -Wall -g -c ViewMenu.cpp -o build/ViewMenu.o

clean:
	rm build/*