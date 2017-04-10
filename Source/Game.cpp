#include "Game.h";

Game::Game() {
	count = 0;
}

void Game::increment() {
	count++;
}

int Game::retrieve() {
	return count;
}