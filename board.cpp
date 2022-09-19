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
  std::cout << "\n\n\n\n";
}

void Board::setValid(const bool& valid) {
  _Valid = valid;
}

bool Board::getValid() {
  return _Valid;
}

void Board::moveDame(Piece& piece, const int& xTarget, const int& yTarget, Player& white, Player& black){
  const int xStart = piece.getX();
  const int yStart = piece.getY();
  const int piece_info = piece.getInfo();
  int x = xStart;
  int y = yStart;
 
  if(abs(xTarget-xStart) == abs(yTarget-yStart)){

    if(piece_info == Stat::white_Dame){
      int xNew;
      int yNew;
      while(x != xTarget && y != yTarget){
        x++;
        y++;
        if(Board::board[x][y] == Stat::black_Dame || Board::board[x][y] == Stat::black_Stein){
          int checkX = x++; 
          int checkY = y++;
          if(Board::board[checkX][checkY] == Stat::black_empty){
            piece.setPlace(checkX, checkY);
            moveDame(piece, xTarget, yTarget, white, black);
          } else {
            std::cout << "not allowed to play!\n" << std::endl;
            std::cout << "xNew: ";
            std::cin >> xNew;
            std::cout << "yNew; ";
            std::cin >> yNew;
            moveDame(piece, xNew, yNew, white, black);
          }
        }
      Board::setValid(true);
      }
    } 
    else if(piece_info == Stat::black_Dame){
      int xNew;
      int yNew;
      while(x != xTarget && y != yTarget){
        x++;
        y++;
        if(Board::board[x][y] == Stat::white_Dame || Board::board[x][y] == Stat::white_Stein){
          int checkX = x++; 
          int checkY = y++;
          if(Board::board[checkX][checkY] == Stat::black_empty){
            piece.setPlace(checkX, checkY);
            moveDame(piece, xTarget, yTarget, white, black);
          } else {
            std::cout << "not allowed to play!\n" << std::endl;
            std::cout << "xNew: ";
            std::cin >> xNew;
            std::cout << "yNew; ";
            std::cin >> yNew;
            moveDame(piece, xNew, yNew, white, black);
          }
        }
      Board::setValid(true);
      }
    }

  }
}

// WORK IN PROGRESS, NOT TESTED YET
void Board::move(Piece& piece, const int& xTarget, const int& yTarget, Player& white, Player& black) {
  const int xStart = piece.getX();
  const int yStart = piece.getY();
  const int piece_info = piece.getInfo();
  
  if(isOccupied(xTarget, yTarget)){
    std::cout << "This place is occupied!!" << std::endl;
    setValid(false);
  }
  else if(piece_info == Stat::black_Dame || piece_info == Stat::white_Dame){
    moveDame(piece,xTarget,yTarget,white, black);
  }
  else if(piece_info == Stat::white_Stein && xTarget - xStart == -1 && abs(yTarget - yStart) == 1 ) {
    Board::board[xStart][yStart] = Stat::black_empty;
    piece.setPlace(xTarget,yTarget);
    setValid(true);
  } 
  else if(piece_info == Stat::white_Stein && xTarget - xStart == -2 && abs(yTarget - yStart) == 2 ) {
    int xEnemy = (xStart + xTarget)/2; // x loc of possible black piece
    int yEnemy = (yStart + yTarget)/2; // y loc of possible black piece

    int xNext;
    int yNext;

    if(Board::board[xEnemy][yEnemy] == Stat::white_Stein || Board::board[xEnemy][yEnemy] == Stat::white_Dame){
      std::cout << "you cant jump over this piece!!" << std::endl;
      setValid(false);
    }
    else if(Board::board[xEnemy][yEnemy] == Stat::black_Stein || Board::board[xEnemy][yEnemy] == Stat::black_Dame){
      Board::board[xStart][yStart] = Stat::black_empty;  // set the square free
      piece.setPlace(xTarget,yTarget); // new location of that piece
      

      if((Board::board[xTarget-1][yTarget-1] == Stat::black_Stein || Board::board[xTarget-1][yTarget-1] == Stat::black_Dame) && !isOccupied(xTarget+2,yTarget-2))
      {
        move(piece, xTarget-2, yTarget-2, white, black);
      }
      else if((Board::board[xTarget-1][yTarget+1] == Stat::black_Stein || Board::board[xTarget+1][yTarget+1] == Stat::black_Dame)&&!isOccupied(xTarget-2,yTarget+2))
      {
        move(piece, xTarget-2, yTarget+2, white, black);
      }
      else if(Board::board[xTarget-3][yTarget-3] == Stat::black_Stein || Board::board[xTarget-3][yTarget-3] == Stat::black_Dame || Board::board[xTarget-3][yTarget+3] == Stat::black_Stein || Board::board[xTarget-3][yTarget+3] == Stat::black_Dame) {
        if(!isOccupied(xTarget-3, yTarget-3) && !isOccupied(xTarget-3,yTarget+3)){
          std::cout << "choose next move: ( White = " << white.getAmount() << " pieces)\n";
          std::cout << "xNext: ";
          std::cin >> xNext;
          std::cout << "yNext: ";
          std::cin >> yNext;
          move(piece, xNext, yNext, white, black);
        }
      }

      for(auto it : collection){
        if(it.getX() == xEnemy && it.getY() == yEnemy){
          Board::board[xEnemy][yEnemy] = Stat::black_empty; // set the square of possible black piece free
          black.setAmount(1);
          it.setPlace(99,99);
        }
      }
    }
    setValid(true); 
  }
  else if(piece_info == Stat::black_Stein && xTarget - xStart == 1 && abs(yTarget - yStart) == 1 ) {
    Board::board[xStart][yStart] = Stat::black_empty;
    piece.setPlace(xTarget,yTarget);
    setValid(true);
  }
  else if(piece_info == Stat::black_Stein && xTarget - xStart == 2 && abs(yTarget - yStart) == 2 ){
    int xEnemy = (xStart + xTarget)/2; // x loc of possible white piece
    int yEnemy = (yStart + yTarget)/2; // y loc of possible white piece
    
    int xNext;
    int yNext;

    if(Board::board[xEnemy][yEnemy] == Stat::black_Stein || Board::board[xEnemy][yEnemy] == Stat::black_Dame){
      std::cout << "you cant jump over this piece!!" << std::endl;
      setValid(false);
    }
    else if(Board::board[xEnemy][yEnemy] == Stat::white_Stein || Board::board[xEnemy][yEnemy] == Stat::white_Dame){
      Board::board[xStart][yStart] = Stat::black_empty;  // set the square free
      piece.setPlace(xTarget,yTarget);  // new location of that piece

      if((Board::board[xTarget+1][yTarget-1] == Stat::white_Stein || Board::board[xTarget+1][yTarget-1] == Stat::white_Dame) && !isOccupied(xTarget+2, yTarget-2))
      {
          move(piece, xTarget+2, yTarget-2, white, black);
      }

      else if((Board::board[xTarget+1][yTarget+1] == Stat::white_Stein || Board::board[xTarget+1][yTarget+1] == Stat::white_Dame)&&!isOccupied(xTarget+2, yTarget+2))
      {
          move(piece, xTarget+2, yTarget+2, white, black);
      }

      else if(Board::board[xTarget+3][yTarget-3] == Stat::white_Stein || Board::board[xTarget+3][yTarget-3] == Stat::white_Dame || Board::board[xTarget+3][yTarget+3] == Stat::white_Stein || Board::board[xTarget+3][yTarget+3] == Stat::white_Dame) 
      {
        if(!isOccupied(xTarget+3, yTarget-3) && !isOccupied(xTarget+3,yTarget+3)){
          std::cout << "choose next move: ( black = " << black.getAmount() << " pieces)";
          std::cout << "xNext: ";
          std::cin >> xNext;
          std::cout << "yNext: ";
          std::cin >> yNext;
          move(piece, xNext, yNext, white, black);
        }
      }

      for(auto it : collection){
        if(it.getX() == xEnemy && it.getY() == yEnemy){
          Board::board[xEnemy][yEnemy] = Stat::black_empty; // set the square of possible white piece free
          white.setAmount(1);
          it.setPlace(99,99);
        }
      }
    }
    setValid(true);
  }
  if(piece.getInfo() == Stat::black_Stein && piece.getX() == 7){
    piece.setDame(piece);
  } else if(piece.getInfo() == Stat::white_Stein && piece.getX() == 0) {
    piece.setDame(piece);
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
