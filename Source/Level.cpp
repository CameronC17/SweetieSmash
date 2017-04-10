#include "Level.h"
#include <iostream>
#include <string>

Level::Level() {

}

Level::Level(int x, int y) : _width(x), _height(y) {
	blocks = new char*[_width];
	for (int i = 0; i < _width; i++)
		blocks[i] = new char[_height];
}

Level::~Level() {
	for (int i = 0; i < _width; i++)
		delete[] blocks[i];
	delete[] blocks;
}

void Level::topBar() {
	std::cout << "//////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "/////////                  SWEETIE SMASH               ///////////" << std::endl;
	std::cout << "/////////   Lives: BLAH          POINTS: ALSO BLAH     ///////////" << std::endl;
	std::cout << "//////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "//    A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S   //" << std::endl;
	std::cout << "//--------------------------------------------------------------//" << std::endl;
}

void Level::draw() {
	//clear the console. lol this is not a hack i promise
	std::cout << std::string(40, '\n');

	topBar();
}

