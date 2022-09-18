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

  std::cout << "color: (1: White, 5:Black) " << board.collection[13].getInfo() <<std::endl; // Funktioniert. es gibt genau 24 Steine.
  std::cout << "xStart: " << board.collection[2].getX() << std::endl; // Funktioniert. es gibt genau 24 Steine.
  std::cout << "yStart: " << board.collection[2].getY() << std::endl; // Funktioniert. es gibt genau 24 Steine.
  std::cout << "xStart: " << board.collection[1].getX() << std::endl; // Funktioniert. es gibt genau 24 Steine.
  std::cout << "yStart: " << board.collection[1].getY() << std::endl; // Funktioniert. es gibt genau 24 Steine.

  // funktioniert.  collection[0]->collection[11]: White ...... collection[12]->collection[23]: Black
  board.move(board.collection[1], 3,4);

  board.PrintBoard();

  std::cout << "\n\n----------------------\n" << std::endl;

  board.move(board.collection[2], 4,3);

  board.PrintBoard();

  std::cout << "xTarget: "<< board.collection[2].getX() << std::endl; // Funktioniert. es gibt genau 24 Steine.
  std::cout << "yTarget: "<< board.collection[2].getY() << std::endl; // Funktioniert. es gibt genau 24 Steine.

  std::cout << "xTarget: "<< board.collection[1].getX() << std::endl; // Funktioniert. es gibt genau 24 Steine.
  std::cout << "yTarget: "<< board.collection[1].getY() << std::endl; // Funktioniert. es gibt genau 24 Steine.

  std::cout << "----------------------" << std::endl;

  return 0;
}
