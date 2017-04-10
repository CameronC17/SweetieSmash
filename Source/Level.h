#pragma once

class Level {
private:
	int _width, _height;
	char **blocks;
	void topBar();
public:
	Level();
	Level(int x, int y);
	~Level();
	void draw();
};