#define QUIT 'q'
#define PLAY 'p'

#include <iostream>
#include "Game.h"

void checkForPlayerInput(char *choice) {
	char input;
    std::cout << std::string(60, '\n');
    std::cout << "What would you like to do?" << std::endl;
	std::cout << "p: Play game // q: quit" << std::endl;
	std::cin >> input;
	*choice = input;
}

int main() {
	char choice;
	Game g = Game();
	std::cout << "WELCOME TO SWEETIE SMASH" << std::endl;
	checkForPlayerInput(&choice);
	
	while (choice != QUIT) {
		switch (choice) {
		case 'p':
			g.newLevel();
			break;
		default:
			std::cout << "Unknown command. Please try again." << std::endl;
			break;
		}

		checkForPlayerInput(&choice);
	}

	std::cout << "Thanks for playing. See ya later!" << std::endl;
    return 0;
}
