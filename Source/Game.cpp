#define CTRL_CHAR '-'

#include "Game.h"
#include <iostream>

Game::Game() {

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
        _message = "Player has entered a command";
    } else {
        _message = "Player has entered a move";
    }
    draw();
}

void Game::newLevel() {
    _lvl = Level(5, 5);
    draw();
}

void Game::endLevel() {

}

void Game::draw() {
    //clear the console. lol this is not a hack i promise
    std::cout << std::string(60, '\n');

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
    std::cout << "/////                                                          //////" << std::endl;
}

void Game::gamePanel() {
    std::cout << "// 1|                                                            | //" << std::endl;
    std::cout << "// 2|                                                            | //" << std::endl;
    std::cout << "// 3|                                                            | //" << std::endl;
    std::cout << "// 4|                                                            | //" << std::endl;
    std::cout << "// 5|                                                            | //" << std::endl;
    std::cout << "// 6|                                                            | //" << std::endl;
    std::cout << "// 7|                                                            | //" << std::endl;
    std::cout << "// 8|                                                            | //" << std::endl;
    std::cout << "// 9|                                                            | //" << std::endl;
    std::cout << "//10|                                                            | //" << std::endl;
    std::cout << "//11|                                                            | //" << std::endl;
    std::cout << "//12|                                                            | //" << std::endl;
    std::cout << "//13|                                                            | //" << std::endl;
    std::cout << "//14|                                                            | //" << std::endl;
    std::cout << "//15|                                                            | //" << std::endl;
    std::cout << "//16|                                                            | //" << std::endl;
    std::cout << "//17|                                                            | //" << std::endl;
    std::cout << "//18|                                                            | //" << std::endl;
    std::cout << "//19|                                                            | //" << std::endl;
    std::cout << "//20|                                                            | //" << std::endl;
}
