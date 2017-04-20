#include "Level.h"
#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Level::Level() {
    std::cout << "You've tried to create a level without any size." << std::endl;
}

Level::Level(int x, int y) : _width(x), _height(y) {
    generateBlocks();
    createRow();
}

Level::~Level() {
//	for (int i = 0; i < _width; i++)
//		delete[] blocks[i];
//	delete[] blocks;
}

void Level::generateBlocks() {
    //blocks.resize(_height);
    srand((unsigned) time(NULL));
    //std::generate_n(std::back_inserter(blocks), _height, createRow());
}

std::vector<char> Level::createRow() {
    std::vector<char> row (_width);
    //std::fill(row.begin(), row.end(), createTile());
    for (int i = 0; i < _width; i++) {
       row.push_back(createTile(5));
    }
    std::ostream_iterator< char > output( std::cout, " " ); //useful
    std::copy(row.begin(), row.end(), output);  //useful
    return row;
}

char Level::createTile(int difficulty) {
    int r = rand() % difficulty; //rnd between 0 and
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
