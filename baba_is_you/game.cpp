#include <iostream>

#include "game.h"



Game::Game(Board &board, Level &level) : _board(board), _level(level){
}

Board Game::getBoard(){
    return this->_board;
}

void Game::renderBoard(){
    this->_board.fillBoard(this->_level.getMap());
}
