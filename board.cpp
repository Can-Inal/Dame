#include "board.hpp"


Board::Board(){
  
  for(int x = 0; x<8; x++){
    for(int y = 0; y<8; y++){
      if((x+y)%2 == 0)
        board[x][y] = Stat::white_empty;
      else
        board[x][y] = Stat::black_empty;
    }
  }

  // for white pieces!!
  for(int x = 5; x<8; x++){
    for(int y = 0; y<8; y++){
      if(board[x][y] == Stat::black_empty){
        board[x][y] = Stat::white_Stein;
        collection.push_back(Piece(x,y, Stat::white_Stein, false));
      }
    }
  }

  // for black pieces!!
  for(int x = 0; x<3; x++){
    for(int y = 0; y<8; y++){
      if(board[x][y] == Stat::black_empty){
        board[x][y] = Stat::black_Stein;
        collection.push_back(Piece(x,y, Stat::black_Stein, false));
      }
    }
  }
}




void Board::PrintBoard(){

  for(int x = 0; x<8; x++){
    for(int y = 0; y<8; y++){
      std::cout << board[x][y];
      std::cout << "---";
    }
    std::cout << std::endl;
  }
}


// WORK IN PROGRESS, NOT TESTED YET
void Board::move(Piece& piece, const int& xTarget, const int& yTarget) {
  const int xStart = piece.getX();
  const int yStart = piece.getY();
  const int piece_info = piece.getInfo();
  
  if(isOccupied(xTarget, yTarget)){
    std::cout << "This place is occupied!!" << std::endl;
  }
  else if(piece_info == Stat::white_Stein && xStart - xTarget == 2 && abs(yTarget - yStart) == 2 ) {
    int xEnemy = (xStart + xTarget)/2; // x loc of possible black piece
    int yEnemy = (yStart + yTarget)/2; // y loc of possible black piece


    if(Board::board[xEnemy][yEnemy] == Stat::white_Stein || Board::board[xEnemy][yEnemy] == Stat::white_Dame){
      std::cout << "you cant jump over this piece!!" << std::endl;
    }
    else if(Board::board[xEnemy][yEnemy] == Stat::black_Stein || Board::board[xEnemy][yEnemy] == Stat::black_Dame){
      Board::board[xStart][yStart] = Stat::black_empty;  // set the square free
      piece.setPlace(xTarget,yTarget);  // new location of that piece
      
      for(auto it : collection){
        if(it.getX() == xEnemy && it.getY() == yEnemy){
          Board::board[xEnemy][yEnemy] = Stat::black_empty; // set the square of possible black piece free
          it.~Piece();// it musst geloscht werden.
        }
      }
      Update(piece);
    }else if(Board::board[xEnemy][yEnemy] == Stat::black_empty){
      Board::board[xStart][yStart] = Stat::black_empty;  // set the square free
      piece.setPlace(xTarget,yTarget);  // new location of that piece
      Update(piece);
    }
  } 
  else if(piece_info == Stat::black_Stein && xTarget - xStart == 2 && abs(yTarget - yStart) == 2 ) {
    int xEnemy = (xStart + xTarget)/2; // x loc of possible white piece
    int yEnemy = (yStart + yTarget)/2; // y loc of possible white piece
    
    if(Board::board[xEnemy][yEnemy] == Stat::black_Stein || Board::board[xEnemy][yEnemy] == Stat::black_Dame)
      std::cout << "you cant jump over this piece!!" << std::endl;

    else if(Board::board[xEnemy][yEnemy] == Stat::white_Stein || Board::board[xEnemy][yEnemy] == Stat::white_Dame){
      Board::board[xStart][yStart] = Stat::black_empty;  // set the square free
      piece.setPlace(xTarget,yTarget);  // new location of that piece
      
      for(auto it : collection){
        if(it.getX() == xEnemy && it.getY() == yEnemy){
          Board::board[xEnemy][yEnemy] = Stat::black_empty; // set the square of possible white piece free
          it.~Piece();
          // it musst geloscht werden.
        }
      }
      Update(piece);
    }else if(Board::board[xEnemy][yEnemy] == Stat::black_empty){
      Board::board[xStart][yStart] = Stat::black_empty;  // set the square free
      piece.setPlace(xTarget,yTarget);  // new location of that piece
      Update(piece);
    } else{
      std::cout << "Error" << std::endl;
    } 
  }   
}


// TESTED
bool Board::isOccupied(const int& xTarget, const int& yTarget) {
  
  if(Board::board[xTarget][yTarget] == Stat::black_empty){
    return false; //not occupied
  } else
    return true;
}


// Change the codes of the board if a piece moves.
void Board::Update(Piece& piece){
  const int x_cord = piece.getX();
  const int y_cord = piece.getY();
  const int info = piece.getInfo();
  const bool Dame = piece.isDame();
  if(info == Stat::white_Dame) {
    Board::board[x_cord][y_cord] = Stat::white_Dame;
  }
  else if(info == Stat::black_Dame) {
    Board::board[x_cord][y_cord] = Stat::black_Dame;
  }
  else if(info == Stat::white_Stein) {
    Board::board[x_cord][y_cord] = Stat::white_Stein;
  }
  else if(info == Stat::black_Stein) {
    Board::board[x_cord][y_cord] = Stat::black_Stein;
  }

}


/* 
  TO DO LIST
  1- Spielende => gameLoop.hpp kann benotigt werden
  2- Wer ist dran ? => Player.hpp auch fur Anzahl von Steinen bei einem Spieler
  3- kann der Stein noch weiter springen ?
*/