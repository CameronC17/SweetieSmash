#include "Game.h";

Game::Game() {

}

void Game::newLevel() {
	_lvl = Level(5, 5);
	draw();
}

void Game::endLevel() {

}

void Game::draw() {
	_lvl.draw();
}