#pragma once

#include <vector>

class Level {
private:
	int _width, _height;
    std::vector<std::vector<char>> blocks;
    void generateBlocks();
    std::vector<char> createRow();
    char createTile(int);
public:
	Level();
	Level(int x, int y);
	~Level();
};
