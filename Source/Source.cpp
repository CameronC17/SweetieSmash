#define QUIT 'q'
#define PLAY 'p'

#include <iostream>
#include "Game.h"

char checkForPlayerInput(bool clear) {
	char input;
	if (clear)
    	std::cout << std::string(60, '\n');
    std::cout << "What would you like to do?" << std::endl;
	std::cout << "p: Play game // q: quit" << std::endl;
	std::cin >> input;
    return input;
}

int main() {
	char choice;
	Game g = Game();
	std::cout << "WELCOME TO SWEETIE SMASH" << std::endl;
	choice = checkForPlayerInput(false);

	while (choice != QUIT) {
		switch (choice) {
		case PLAY:
			g.newLevel();
			break;
		case QUIT:
			break;
		default:
			std::cout << "Unknown command: " << choice << ". Please try again." << std::endl;
			break;
		}

		choice = checkForPlayerInput(true);
	}

	std::cout << "Thanks for playing. See ya later!" << std::endl;
    return 0;
}
