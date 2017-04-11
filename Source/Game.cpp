#include "Game.h"
#include <iostream>

Game::Game() {

}

void Game::getInput() {
    char input;
    std::cout << "What would you like to do?" << std::endl;
    std::cin >> input;
    
}

void Game::newLevel() {
    _lvl = Level(5, 5);
    draw();
    getInput();
}

void Game::endLevel() {

}

void Game::draw() {
	_lvl.draw();
}
