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
    
    // Bool function to determine if the move is valid
    void move(Piece& piece,const int& xTarget,const int& yTarget);

    // Bool function to determine if the square occupied by any piece
    bool isOccupied(const int& x_cord, const int& y_cord);

    // Update the board after every move
    void Update(Piece& piece);    

    std::vector<Piece> collection;

  private:
    int board[8][8];
  
};




#endif
