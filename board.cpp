#include "board.hpp"
#include "piece.hpp"


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

  int y = 0;
  for(int x = 0; x< 8; x++){
        for(int i = 0; i<4; i++) {
            if(x%2 == 0){
                for(int k = 0; k<4; k++){
                  if(i==0 && k==0){
                    printf("\033[30;47m%d       \033[0m", abs(x-8)); // White
                    printf("\033[47;40m        \033[0m"); // Black
                  }else if(i==3&&x==7){
                    static int inc = 0;
                    printf("\033[30;47m       %c\033[0m",(char)65+inc); // White
                    printf("\033[47;40m       %c\033[0m",(char)65+inc+1); // Black
                    inc+=2;
                  }
                  else{
                    printf("\033[30;47m        \033[0m"); // White
                    printf("\033[47;40m        \033[0m"); // Black
                  }
                }
                printf("\n");
            } else {
                for(int k = 0; k<4; k++){
                  if(i==0 && k==0){
                    printf("\033[47;40m%d       \033[0m", abs(x-8)); // Black
                    printf("\033[30;47m        \033[0m"); // White
                  }else if(i==3&&x==7){
                    static int inc = 0;
                    printf("\033[47;40m       %c\033[0m",(char)65+inc); // Black
                    printf("\033[30;47m       %c\033[0m",(char)65+inc+1); // White
                    inc+=2;
                  }
                  else{
                    printf("\033[47;40m        \033[0m"); // Black
                    printf("\033[30;47m        \033[0m"); // White
                  }
                }
                printf("\n");
            }   
        }
  }
  std::cout << "\n\n\n";
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
  int xTarg = xTarget;
  int yTarg = yTarget;
 
  if(abs(xTarget-xStart) == abs(yTarget-yStart)){
  
    // The code begins here for white king
    // ----------------White King--------------
    if(piece_info == Stat::white_Dame){

      // White king right bottom corner direction
      if(xTarget > x && yTarget > y){
        while(xTarg != x){
          xTarg--;
          yTarg--;
          if(Board::board[xTarg][yTarg] == Stat::black_Stein){
            if(Board::board[xTarg+1][yTarg+1] == Stat::black_empty){
              for(auto it : collection){
                if(it.getX() == xTarg && it.getY() == yTarg){
                  Board::board[xTarg][yTarg] = Stat::black_empty; // set the square of possible black piece free
                  it.setPlace(99,99);
                }
              }
              Board::board[xStart][yStart] = Stat::black_empty;
              black.setAmount(1);
              Board::board[xStart][yStart] = Stat::black_empty;
              piece.setPlace(xTarget, yTarget);
              setValid(true);
            }
          }
        }
      }



      // White king left bottom corner direction
      else if(xTarget > x && yTarget < y){
        while(xTarg != x){
          xTarg--;
          yTarg++;
          if(Board::board[xTarg][yTarg] == Stat::black_Stein){
            if(Board::board[xTarg+1][yTarg-1] == Stat::black_empty){
              for(auto it : collection){
                if(it.getX() == xTarg && it.getY() == yTarg){
                  Board::board[xTarg][yTarg] = Stat::black_empty; // set the square of possible black piece free
                  it.setPlace(99,99);
                }
              }
              Board::board[xStart][yStart] = Stat::black_empty;
              black.setAmount(1);
              piece.setPlace(xTarget, yTarget);
              setValid(true);
            }
          }
        }
      }

     // White king right top corner direction
      else if(xTarget < x && yTarget > y){
        while(xTarg != x){
          xTarg++;
          yTarg--;
          if(Board::board[xTarg][yTarg] == Stat::black_Stein){
            if(Board::board[xTarg-1][yTarg+1] == Stat::black_empty){
              for(auto it : collection){
                if(it.getX() == xTarg && it.getY() == yTarg){
                  Board::board[xTarg][yTarg] = Stat::black_empty; // set the square of possible black piece free
                  it.setPlace(99,99);
                }
              }
              Board::board[xStart][yStart] = Stat::black_empty;
              black.setAmount(1);
              piece.setPlace(xTarget, yTarget);
              std::cout << "xStart, yStart: " << Board::board[xStart][yStart] << std::endl;
              setValid(true);
            }
          }
        }
      }


      // White king left top corner direction
      else if(xTarget < x && yTarget < y){
        while(xTarg != x){
          xTarg++;
          yTarg++;
          if(Board::board[xTarg][yTarg] == Stat::black_Stein){
            if(Board::board[xTarg-1][yTarg-1] == Stat::black_empty){
              for(auto it : collection){
                if(it.getX() == xTarg && it.getY() == yTarg){
                  Board::board[xTarg][yTarg] = Stat::black_empty; // set the square of possible black piece free
                  it.setPlace(99,99);
                }
              }
              Board::board[xStart][yStart] = Stat::black_empty;
              black.setAmount(1);
              piece.setPlace(xTarget, yTarget);
              std::cout << "xStart, yStart: " << Board::board[xStart][yStart] << std::endl;
              setValid(true);
            }
          }
        }
      }




    }
    
    // The code begins here for Black king
    // ----------------Black King--------------
    else if(piece_info == Stat::black_Dame){


         // Black king right bottom corner direction
      if(xTarget > x && yTarget > y){
        while(xTarg != x){
          xTarg--;
          yTarg--;
          if(Board::board[xTarg][yTarg] == Stat::white_Stein){
            if(Board::board[xTarg+1][yTarg+1] == Stat::black_empty){
              for(auto it : collection){
                if(it.getX() == xTarg && it.getY() == yTarg){
                  Board::board[xTarg][yTarg] = Stat::black_empty; // set the square of possible black piece free
                  it.setPlace(99,99);
                }
              }
              black.setAmount(1);
              Board::board[xStart][yStart] = Stat::black_empty;
              piece.setPlace(xTarget, yTarget);
              setValid(true);
            }
          }
        }
      }



      // Black king left bottom corner direction
      else if(xTarget > x && yTarget < y){
        while(xTarg != x){
          xTarg--;
          yTarg++;
          if(Board::board[xTarg][yTarg] == Stat::white_Stein){
            if(Board::board[xTarg+1][yTarg-1] == Stat::black_empty){
              for(auto it : collection){
                if(it.getX() == xTarg && it.getY() == yTarg){
                  Board::board[xTarg][yTarg] = Stat::black_empty; // set the square of possible black piece free
                  it.setPlace(99,99);
                }
              }
              Board::board[xStart][yStart] = Stat::black_empty;
              black.setAmount(1);
              piece.setPlace(xTarget, yTarget);
              std::cout << "xStart, yStart: " << Board::board[xStart][yStart] << std::endl;
              setValid(true);
            }
          }
        }
      }

     // Black king right top corner direction
      else if(xTarget < x && yTarget > y){
        while(xTarg != x){
          xTarg++;
          yTarg--;
          if(Board::board[xTarg][yTarg] == Stat::white_Stein){
            if(Board::board[xTarg-1][yTarg+1] == Stat::black_empty){
              for(auto it : collection){
                if(it.getX() == xTarg && it.getY() == yTarg){
                  Board::board[xTarg][yTarg] = Stat::black_empty; // set the square of possible black piece free
                  it.setPlace(99,99);
                }
              }
              Board::board[xStart][yStart] = Stat::black_empty;
              black.setAmount(1);
              piece.setPlace(xTarget, yTarget);
              std::cout << "xStart, yStart: " << Board::board[xStart][yStart] << std::endl;
              setValid(true);
            }
          }
        }
      }


      // Black king left top corner direction
      else if(xTarget < x && yTarget < y){
        while(xTarg != x){
          xTarg++;
          yTarg++;
          if(Board::board[xTarg][yTarg] == Stat::white_Stein){
            if(Board::board[xTarg-1][yTarg-1] == Stat::black_empty){
              for(auto it : collection){
                if(it.getX() == xTarg && it.getY() == yTarg){
                  Board::board[xTarg][yTarg] = Stat::black_empty; // set the square of possible black piece free
                  it.setPlace(99,99);
                }
              }
              Board::board[xStart][yStart] = Stat::black_empty;
              black.setAmount(1);
              piece.setPlace(xTarget, yTarget);
              std::cout << "xStart, yStart: " << Board::board[xStart][yStart] << std::endl;
              setValid(true);
            }
          }
        }
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

    if(Board::board[xEnemy][yEnemy] == Stat::white_Stein || Board::board[xEnemy][yEnemy] == Stat::white_Dame || Board::board[xEnemy][yEnemy] == Stat::white_empty ||Board::board[xEnemy][yEnemy] == Stat::black_empty){
      std::cout << "you cant jump over this piece!!" << std::endl;
      setValid(false);
    }
    else if(Board::board[xEnemy][yEnemy] == Stat::black_Stein || Board::board[xEnemy][yEnemy] == Stat::black_Dame){
      Board::board[xStart][yStart] = Stat::black_empty;  // set the square free
      piece.setPlace(xTarget,yTarget);  // new location of that piece
      if(xTarget == 0)
        piece.setDame(piece);

      if((Board::board[xTarget-1][yTarget-1] == Stat::black_Stein || Board::board[xTarget-1][yTarget-1] == Stat::black_Dame) && !isOccupied(xTarget-2,yTarget-2))
      {
        move(piece, xTarget-2, yTarget-2, white, black); 
      }
      else if((Board::board[xTarget-1][yTarget+1] == Stat::black_Stein || Board::board[xTarget-1][yTarget+1] == Stat::black_Dame)&&!isOccupied(xTarget-2,yTarget+2))
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
      setValid(true); 
    }
  }
  else if(piece_info == Stat::black_Stein && xTarget - xStart == 1 && abs(yTarget - yStart) == 1 ) {
    Board::board[xStart][yStart] = Stat::black_empty;
    piece.setPlace(xTarget,yTarget);
  }
  else if(piece_info == Stat::black_Stein && xTarget - xStart == 2 && abs(yTarget - yStart) == 2 ){
    int xEnemy = (xStart + xTarget)/2; // x loc of possible white piece
    int yEnemy = (yStart + yTarget)/2; // y loc of possible white piece
    
    int xNext;
    int yNext;

    if(Board::board[xEnemy][yEnemy] == Stat::black_Stein || Board::board[xEnemy][yEnemy] == Stat::black_Dame || Board::board[xEnemy][yEnemy] == Stat::white_empty ||Board::board[xEnemy][yEnemy] == Stat::black_empty){
      std::cout << "you cant jump over this piece!!" << std::endl;
      setValid(false);
    }
    else if(Board::board[xEnemy][yEnemy] == Stat::white_Stein || Board::board[xEnemy][yEnemy] == Stat::white_Dame){
      Board::board[xStart][yStart] = Stat::black_empty;  // set the square free
      piece.setPlace(xTarget,yTarget);  // new location of that piece
      if(xTarget == 7)
        piece.setDame(piece);

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
       setValid(true);
    }
  }else if((xTarget == 0 || xTarget == 7) && (piece_info == Stat::white_Stein || piece_info == Stat::black_Stein)){
    piece.setDame(piece);
    Update(piece);
  }
  else {
    std::cout << "not possible! " << std::endl;
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



