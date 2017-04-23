#pragma once

#include <string>
#include "Level.h"

class Game {
private:
	int _width, _height;
	Level _lvl;
	std::string _msg;

    void getInput();
	void processInput(std::string);
	void processCommand(std::string);
	void processMove(std::string);
    void topBar();
    void bottomBar();
    void gamePanel();
	void printRow(int);
	void messagePanel();
public:
	Game();
	void newLevel();
	void endLevel();
	void draw();
};
