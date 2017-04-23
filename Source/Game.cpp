#define CTRL_CHAR '-'
#define MSG_SPACE 58
#define ROW_SPACE 60
#define CLEAR_LINE 20

#include "Game.h"
#include <iostream>
#include <vector>
#include <sstream>

Game::Game() {
    _width = 3;
    _height = 3;
}

void Game::getInput() {
    std::string input;
    std::cout << "What would you like to do?" << std::endl;
    std::cin >> input;
    processInput(input);
}

void Game::processInput(std::string input) {
    //checking if the user has entered a command
    if (input.at(0) == CTRL_CHAR) {
        processCommand(input);
    } else {
        if (input.size() == 4)
            processMove(input);
        else
            _msg = "Wrong entry format. Should be 4 chars.";
    }
    draw();
}

void Game::processMove(std::string move) {
    //this line gets the first char of the input string, forces to lower case and then minuses 97, the ascii char for 'a'.
    //this gives me an int value for what column the user has picked
    int x = std::tolower(move.at(0)) - 97;

    int y = std::stoi(move.substr(1, 2)); //gotta remember to take 1 off this when checking with the array!

    char m = std::tolower(move.at(3));

    //safety checks from user input
    if (x >= 0 && x < 20 && y > 0 && y <= 20 && ((m == 'u') || (m == 'd') || (m == 'l') || (m == 'r'))) {
        _msg = "Col is: " + std::to_string(x) + " and row is: " + std::to_string(y) + " moved " + m;
        _lvl.moveTileCommand(x, y-1, m, _msg);
    } else {
        _msg = "There is an error with your input.";
    }
}

void Game::processCommand(std::string command) {
    if (command == "-r") {
        _msg = "Reset command. New game started.";
        newLevel();
    } else {
        _msg = "Unknown command. Please try again.";
    }
}

void Game::newLevel() {
    _lvl = Level(_width, _height);
    draw();
}

void Game::endLevel() {

}

void Game::draw() {
    //clear the console. lol this is not a hack i promise
    std::cout << std::string(CLEAR_LINE, '\n');

    topBar();
    gamePanel();
    bottomBar();

    getInput();
}

void Game::topBar() {
    std::cout << "/////////////////////////////////////////////////////////////////////" << std::endl;
    std::cout << "/////////                    SWEETIE SMASH               ////////////" << std::endl;
    std::cout << "/////////        Lives: BLAH       POINTS: ALSO BLAH     ////////////" << std::endl;
    std::cout << "/////////////////////////////////////////////////////////////////////" << std::endl;
    std::cout << "//    A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T   //" << std::endl;
    std::cout << "//   ------------------------------------------------------------  //" << std::endl;
}

void Game::bottomBar() {
    std::cout << "//   ------------------------------------------------------------  //" << std::endl;
    std::cout << "//                                                                 //" << std::endl;
    std::cout << "/////////////////////////////////////////////////////////////////////" << std::endl;
    std::cout << "/////                          Level X                         //////" << std::endl;
    messagePanel();
    std::cout << "/////////////////////////////////////////////////////////////////////" << std::endl;
}

void Game::messagePanel() {
    //58 spaces
    int textSize = _msg.size();
    if (textSize == 0) {
        std::cout << "/////                                                          //////" << std::endl;
    } else {
        std::string infoLine = "/////";
        int spacing = (MSG_SPACE / 2) - ((int) textSize / 2);
        infoLine.append(spacing, ' ');
        infoLine += _msg;
        infoLine.append(spacing, ' ');
        if (textSize % 2 == 0) { infoLine += ' '; }
        infoLine += "/////";
        std::cout << infoLine << std::endl;
    }
}

void Game::gamePanel() {
    for (int rowNumber = 1; rowNumber < 21; rowNumber++) {
       printRow(rowNumber);
    }
}

void Game::printRow(int rowNumber) {
    //were gonna build the string here
    //std::cout << "//" << rowNumber << "|                                                            | //" << std::endl;
    std::string row = "//";
    if (rowNumber < 10) { row += ' '; }
    row += std::to_string(rowNumber);
    row += "|";
    //actual drawing of tiles here
    if (rowNumber - 1 < _height) {
        std::vector<char> v = _lvl.getRow(rowNumber - 1);
        for (int i = 0; i < _width; i++) {
            row += ' ';
            row += v.at(i);
            row += ' ';
        }
        row.append((ROW_SPACE - (_width * 3)), ' ');
    } else {
        row.append(ROW_SPACE, ' ');
    }

    //end tiles
    row += "| //";

    std::cout << row << std::endl;
}
