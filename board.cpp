#include "board.hpp"


Board::Board(){

  for(int x = 0; x<8; x++){
    for(int y = 0; y<8; y++){
      if((x+y) % 2 == 0)
        board[x][y] = White_Sq;
      else
        board[x][y] = Black_Sq;
    }
  }
}


void Board::PrintBoard(){

  for(int x = 0; x<8; x++){
    for(int y = 0; y<8; y++){
      std::cout << board[x][y];
    }
    std::cout << std::endl;
  }

}
