#pragma once

#include <string>
#include "Level.h"

class Game {
private:
	Level _lvl;
	std::string _msg;

    void getInput();
	void processInput(std::string);
    void topBar();
    void bottomBar();
    void gamePanel();
	void messagePanel();
public:
	Game();
	void newLevel();
	void endLevel();
	void draw();
};
