#ifndef GAME_HPP
#define GAME_HPP



#include <iostream>
#include "board.hpp"
#include "player.hpp"

enum Result : int {
    White_won = -1,
    Draw,
    Black_won,
};


class Game {

public:
    void Turn_end(Player& player);
    void gameLoop();
    int getResult() const;
    void setResult(Player& player);

private:
    int _Result = 99;
};


#endif 




