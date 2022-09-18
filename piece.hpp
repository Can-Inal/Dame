#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>

enum Stat : int {
  white_Dame = 0,
  white_Stein,  // = 1 
  white_empty, // = 2
  invalid, // = 3
  black_empty, // = 4
  black_Stein, // = 5
  black_Dame, // = 6
};

class Piece {

  public:
  
    Piece(const int& x, const int& y, const int& info, const bool& Dame);
    ~Piece() = default;

    int getX() const;
    int getY() const;
    void setPlace(const int& x, const int& y);
    int getInfo() const;    
    bool isDame() {return _Dame;}
    void setDame(Piece& piece);
    
    

  private: 
  
    int _x, _y;
    int _info;
    bool _Dame;

};




#endif
