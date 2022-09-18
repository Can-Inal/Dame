#include "game.hpp"


void Game::Turn_end(Player& player){
    player.setTurn(false);
}

void Game::gameLoop(Board& board, Player& white, Player& black) {
    while(!white.loser() || !black.loser() || _Result != 0){
        if(white.getTurn()){
            white.
        }else if (black.getTurn()){
            black.
        }
    }
}

int Game::getResult() const {
    return _Result;
}

void Game::setResult(Player& player) {
    if(player.getColor() == player::White) {
        _Result = Result::White;
    } else if(player.getColor() == player::Black) {
        _Result = Result::Black;
    } else
        _Result = Result::Draw;
}