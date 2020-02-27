passman:
	echo shiet

LoginInfo.o: LoginInfo.cpp LoginInfo.hpp
	g++ -Wall -c LoginInfo.cpp -o build/LoginInfo.o

aes.o: aes/aes.c aes/aes.h aes/aes.hpp
	g++ -Wall -c aes/aes.c -o build/aes.o

sha256.o: sha256/sha256.c sha256/sha256.h sha256/sha256.hpp
	g++ -Wall -c sha256/sha256.c -o build/sha256.o

Crypto.o: Crypto.cpp Crypto.hpp LoginInfo.o aes.o sha256.o
	g++ -Wall -c Crypto.cpp -o build/Crypto.o

SessionInfo.o: SessionInfo.cpp SessionInfo.hpp LoginInfo.o
	g++ -Wall -c SessionInfo.cpp -o build/SessionInfo.o

Menu.o: Menu.cpp Menu.hpp
	g++ -Wall -c Menu.cpp -o build/Menu.o

MenuContext.o: MenuContext.cpp MenuContext.hpp #Menu.o Crypto.o SessionInfo.o MainMenu.o
	g++ -Wall -c MenuContext.cpp -o build/MenuContext.o

clean:
	rm build/*