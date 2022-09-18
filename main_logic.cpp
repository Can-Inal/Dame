#include "board.hpp"

int main(int argc, char *argv[]) {

  std::cout << "----------------------" << std::endl;

  Board board;

  board.PrintBoard();

  std::cout << "----------------------" << std::endl;

  // funktioniert.
  if(board.isOccupied(4,5)){
    std::cout << "occupied\n";
  }else
    std::cout << "not occupied\n";

  std::cout << board.collection[5].getY() << std::endl; // Funktioniert. es gibt genau 24 Steine.

  // muss noch korrigiert werden!
  board.move(board.collection[5], 4,1);
  board.PrintBoard();

  std::cout << "----------------------" << std::endl;

  return 0;
}
