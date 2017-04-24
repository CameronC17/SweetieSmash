#pragma once

#include <vector>
#include <utility>

class Level {
private:
	int _width, _height;
    std::vector<std::vector<char>> _blocks;
	std::vector<std::pair<int, int>> _clearedTiles;
	bool _locked = false;

	void generateBlocks();
    std::vector<char> createRow();
	char createTile(int);
    char createTileFake(int);
	void checkCombos();
	void checkTile(int, int, char, int, int, int&);
	void moveTile(int, int, char, std::string&);
	void clearAndFill();
public:
	Level();
	Level(int x, int y);
	~Level();

	std::vector<char> getRow(int);
	void moveTileCommand(int, int, char, std::string&);
	bool isLocked();
	void unlock();
};
