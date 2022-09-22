#include "game.hpp"


void Game::gameLoop() {
    Board board;
    Player white(player::White, 12, true);
    Player black(player::Black, 12, false);
    int piece;
    int x;
    int y;
    if(white.getAmount() != 0 && black.getAmount() == 0){
      black.setLost(true);
      std::cout << "White won!" << std::endl;
    }else if(black.getAmount() != 0 && white.getAmount() == 0){
      white.setLost(true);
      std::cout << "Black won!" << std::endl;
    }
    while(!white.loser() && !black.loser()){
        if(white.getTurn()){
          board.PrintBoard();
          std::cout << "choose piece: (white = " << white.getAmount() << " pieces)" << std::endl;
          std::cin >> piece;
          std::cout << "x: ";
          std::cin >> x;
          std::cout << "y: ";
          std::cin >> y;
          if(piece <= 11 && piece >= 0){
            board.move(board.collection[piece], x, y, white, black);
            if(board.getValid()){
              white.setTurn(false);
              black.setTurn(true);
            }else {
              white.setTurn(true);
              black.setTurn(false);
            }
            board.Update(board.collection[piece]);
          } else
            std::cout << "wrong type!!" << std::endl;
        }else if (black.getTurn()){
          board.PrintBoard();
          std::cout << "choose piece: (black = " << black.getAmount() << " pieces)" << std::endl;
          std::cin >> piece;
          std::cout << "x: ";
          std::cin >> x;
          std::cout << "y: ";
          std::cin >> y;
          if(piece > 11 && piece <= 23){
            board.move(board.collection[piece], x, y, white, black);
            if(board.getValid()){
              black.setTurn(false);
              white.setTurn(true);
            }else {
              black.setTurn(true);
              white.setTurn(false);
            }
            board.Update(board.collection[piece]);
          } else
            std::cout << "Wrong type!!!" << std::endl;
        }
    }
}


