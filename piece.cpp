#include "piece.hpp"

Piece::Piece(const int& x, const int& y, const int& info, const bool& Dame)
  : _x(x) , _y(y), _info(info), _Dame(Dame) {}

int Piece::getX() const {
  return _x;
}

int Piece::getY() const {
  return _y;
}

void Piece::setPlace(const int& x, const int& y){
  _x = x;
  _y = y;
}

int Piece::getInfo() const {
  return _info;
}

void Piece::setDame(Piece& piece) {
  if(piece.getInfo() == Stat::white_Stein && piece.getX() == 0){
    piece._Dame = true;
    piece._info = Stat::white_Dame;
  } else if(piece.getInfo() == Stat::black_Stein && piece.getX() == 7){
    piece._Dame = true;
    piece._info = Stat::black_Dame;
  }
}

