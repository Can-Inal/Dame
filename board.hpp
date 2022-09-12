#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

#define White_Sq '-'
#define Black_Sq '+'



class Board {
  public:
    Board();
    void PrintBoard();

  private:
    char board[8][8];
};




#endif
