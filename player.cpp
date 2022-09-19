#include "player.hpp"

Player::Player(const int& color, const int& PieceAmount, const bool& turn)
    : _color(color), _PieceAmount(PieceAmount), _Turn(turn) {}

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
    }else {
      return false;
    }
}

void Player::setTurn(const bool& turn) {
    _Turn = turn;
}
