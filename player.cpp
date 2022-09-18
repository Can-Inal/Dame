#include "player.hpp"

Player::Player(const int& color, const int& PieceAmount)
    : _color(color), _PieceAmount(PieceAmount) {}

int Player::getAmount() const{
    return _PieceAmount;
}

void Player::setAmount(const int& var) {
    _PieceAmount = _PieceAmount - var;
}

int Player::getColor() const {
    return _color;
}



bool Player::loser(){
    if(_PieceAmount == 0){
        _Lost = true;
        return _Lost;
    }
}

bool Player::setTurn(const bool& turn) {
    _Turn = turn;
}