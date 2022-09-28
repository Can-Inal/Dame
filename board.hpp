#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include "piece.hpp"
#include "player.hpp"
#include <vector>

#define Max_Size 8;

class Board {
  public:
    Board();

    void PrintBoard();
    
    // move functions
    void move(Piece& piece,const int& xTarget,const int& yTarget, Player& white, Player& black);
    void moveDame(Piece& piece, const int& xTarget, const int& yTarget, Player& white, Player& black);

    // Bool function to determine if the square occupied by any piece
    bool isOccupied(const int& x_cord, const int& y_cord);

    // Update the board after every move
    void Update(Piece& piece);    

    std::vector<Piece> collection;

    int findPiece(const int& x, const int& y, const int& color);

    bool getValid();
    void setValid(const bool& valid);

  private:
    bool _Valid;
    int board[8][8];
  
};




#endif
