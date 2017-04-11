#include "Level.h"
#include <iostream>
#include <string>

Level::Level() {

}

Level::Level(int x, int y) : _width(x), _height(y) {
	blocks = new char*[_width];
	for (int i = 0; i < _width; i++)
		blocks[i] = new char[_height];
    
    generateBlocks();
}

Level::~Level() {
	for (int i = 0; i < _width; i++)
		delete[] blocks[i];
	delete[] blocks;
}

void Level::generateBlocks() {
    std::cout << "Length is: " << **blocks.size() << std::endl;
}

void Level::topBar() {
	std::cout << "/////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "/////////                    SWEETIE SMASH               ////////////" << std::endl;
	std::cout << "/////////        Lives: BLAH       POINTS: ALSO BLAH     ////////////" << std::endl;
	std::cout << "/////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "//    A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T   //" << std::endl;
	std::cout << "//   ------------------------------------------------------------  //" << std::endl;
}

void Level::bottomBar() {
    std::cout << "//   ------------------------------------------------------------  //" << std::endl;
    std::cout << "//                                                                 //" << std::endl;
    std::cout << "/////////////////////////////////////////////////////////////////////" << std::endl;
    std::cout << "/////                          Level X                         //////" << std::endl;
    std::cout << "/////                                                          //////" << std::endl;
    std::cout << "/////////////////////////////////////////////////////////////////////" << std::endl;
}

void Level::gamePanel() {
    std::cout << "// 1|                                                            | //" << std::endl;
    std::cout << "// 2|                                                            | //" << std::endl;
    std::cout << "// 3|                                                            | //" << std::endl;
    std::cout << "// 4|                                                            | //" << std::endl;
    std::cout << "// 5|                                                            | //" << std::endl;
    std::cout << "// 6|                                                            | //" << std::endl;
    std::cout << "// 7|                                                            | //" << std::endl;
    std::cout << "// 8|                                                            | //" << std::endl;
    std::cout << "// 9|                                                            | //" << std::endl;
    std::cout << "//10|                                                            | //" << std::endl;
    std::cout << "//11|                                                            | //" << std::endl;
    std::cout << "//12|                                                            | //" << std::endl;
    std::cout << "//13|                                                            | //" << std::endl;
    std::cout << "//14|                                                            | //" << std::endl;
    std::cout << "//15|                                                            | //" << std::endl;
    std::cout << "//16|                                                            | //" << std::endl;
    std::cout << "//17|                                                            | //" << std::endl;
    std::cout << "//18|                                                            | //" << std::endl;
    std::cout << "//19|                                                            | //" << std::endl;
    std::cout << "//20|                                                            | //" << std::endl;
}

void Level::draw() {
	//clear the console. lol this is not a hack i promise
	std::cout << std::string(60, '\n');

	topBar();
    gamePanel();
    bottomBar();
}

