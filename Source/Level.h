#pragma once

#include <vector>

class Level {
private:
	int _width, _height;
    std::vector<std::vector<char>> _blocks;

	void generateBlocks();
    std::vector<char> createRow();
	char createTile(int);
    char createTileFake(int);
	void checkCombos();
	int checkTile(int, int, char, int);
public:
	Level();
	Level(int x, int y);
	~Level();

	std::vector<char> getRow(int);
};
