#include "Level.h"
#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Level::Level() {
}

Level::Level(int x, int y) : _width(x), _height(y) {
    generateBlocks();
    checkCombos();
}


Level::~Level() {
//	for (int i = 0; i < _width; i++)
//		delete[] _blocks[i];
//	delete[] _blocks;
}

void Level::checkCombos() {
    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++) {
            char tile = _blocks.at(y).at(x);
            int chain = checkTile(x, y, tile, 0);
            //if ( > 2) {
                std::cout << "x:" << x << " y: " << y << "  chain of: " << chain <<std::endl;
            //}
        }
    }
}

int Level::checkTile(int x, int y, char c, int count) {
    //now we have to check before we do each check to ensure we dont go out of the range of the array
    if (x >= 0 && x < _width && y >= 0 && y < _height) {
        if (_blocks.at(y).at(x) == c) {
            count++;

            if (x < _width) {
                count = (checkTile(x + 1, y, c, count));
            }
            if (y < _height) {
                count = (checkTile(x, y + 1, c, count));
            }
        }

    }
    return count;
}

void Level::generateBlocks() {
    srand((unsigned) time(NULL));
    //std::generate_n(std::back_inserter(_blocks), _height, createRow());
    for (int i = 0; i < _height; i++) {
        _blocks.push_back(createRow());
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
