#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include "piece.hpp"


enum player : int {
    White = 1,
    Black,
};

class Player {

public:
    Player(const int& color, const int& PieceAmount);
    int getAmount() const;
    void setAmount(const int& var);
    int getColor() const;
    bool loser();
    bool setTurn(const bool& turn);
    bool getTurn() { return _Turn; }
private:
    const int _color;
    int _PieceAmount;
    bool _Lost;
    bool _Turn;
};

#endif