#include "Level.h"
#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Level::Level() {
}

Level::Level(int x, int y) : _width(x), _height(y) {
    generateBlocks();
}


Level::~Level() {
//	for (int i = 0; i < _width; i++)
//		delete[] _blocks[i];
//	delete[] _blocks;
}

//this function is super messy and shit. come back to it please lol
void Level::checkCombos() {
    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++) {
            char tile = _blocks.at(y).at(x);
            int chain = 0;
            checkTile(x, y, tile, 1, 0, chain);
            if (chain > 2) {
                for (int i = 0; i < chain; i++) {
                    _blocks.at(y).at(x + i) = '$';
                }
            } else {
                chain = 0;
                checkTile(x, y, tile, 0, 1, chain);
                if (chain > 2) {
                    for (int i = 0; i < chain; i++) {
                        _blocks.at(y + i).at(x) = '$';
                    }
                }
            }
        }
    }
}

void Level::checkTile(int x, int y, char c, int across, int down, int &chain) {
    //safety check. cant be below 0 so dont need to check that
    if (x < _width && y < _height) {
        //if we've matched the tile
        if (_blocks.at(y).at(x) == c) {
            chain++;
            checkTile(x + across, y + down, c, across, down, chain);
        }
    }
}

void Level::generateBlocks() {
    srand((unsigned) time(NULL));
    //std::generate_n(std::back_inserter(_blocks), _height, createRow());
    for (int i = 0; i < _height; i++) {
        _blocks.push_back(createRow());
    }
}

void Level::moveTile(int x, int y, char move, std::string &msg) {
    int vert, horz = 0;
    if (move == 'l')
        horz--;
    else if (move == 'u')
        vert--;
    else if (move == 'r')
        horz++;
    else if (move == 'd')
        vert++;

    std::string s;
    s += "Moving tile ";
    s += _blocks.at(y).at(x);
    s += " to the ";
    s += move;
    msg = s;

    char tempTile = _blocks.at(y + vert).at(x + horz);
    _blocks.at(y + vert).at(x + horz) = _blocks.at(y).at(x);
    _blocks.at(y).at(x) = tempTile;

    //were checking the tile matches here as this is the game logic flow
    //checkCombos();
}

void Level::moveTileCommand(int x, int y, char move, std::string &msg) {
    //check to make sure nothing is being moved out of bounds
    if ((move == 'l' && x > 0) || (move == 'u' && y > 0) || (move == 'd' && y < _height - 1) || (move == 'r' && x < _width - 1)) {
        //msg = "Move is OK.";
        moveTile(x, y, move, msg);
    } else {
        msg = "You've tried to move a tile out of bounds.";
    }
}

std::vector<char> Level::createRow() {
    std::vector<char> row;
    //std::fill(row.begin(), row.end(), createTile());
    for (int i = 0; i < _width; i++) {
       row.push_back(createTile(3));
    }
    //std::ostream_iterator< char > output( std::cout, " " ); //useful
    //std::copy(row.begin(), row.end(), output);  //useful
    return row;
}

char Level::createTileFake(int doesntMatter) {
    return 'a';
}

char Level::createTile(int difficulty) {
    int r = rand() % difficulty; //rnd between 0 and difficulty
    switch (r) {
        case 0:
            return 'a';
            break;
        case 1:
            return 'b';
            break;
        case 2:
            return 'c';
            break;
        case 3:
            return 'd';
            break;
        case 4:
            return 'e';
            break;
        case 5:
            return 'f';
            break;
        case 6:
            return 'g';
            break;
        case 7:
            return 'h';
            break;
        case 8:
            return 'i';
            break;
        case 9:
            return 'j';
            break;
        case 10:
            return 'k';
            break;
        default:
            return 'Z';

    }
}

std::vector<char> Level::getRow(int n) {
    return _blocks.at(n);
}
