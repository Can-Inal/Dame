#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include "board.hpp"

enum Result : int {
    White = -1,
    Draw,
    Black,
};

enum player : int {
    White = 1,
    Black,
};

class Game {

public:
    Game();
    void Turn_end(Player& player);
    void gameLoop(Board& board, Player& white, Player& black);
    int getResult() const;
    void setResult(Player& player);

private:
    int _Result = 99;
};

#endif



