#define QUIT 'q'
#define PLAY 'p'

#include <iostream>
#include "Game.h"

void checkForPlayerInput(char *choice) {
	char input;
	std::cout << "p: Play game // q: quit" << std::endl;
	std::cin >> input;
	*choice = input;
}

int main() {
	char choice;
	Game g = Game();
	std::cout << "New game created. What would you like to do?" << std::endl;
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
}