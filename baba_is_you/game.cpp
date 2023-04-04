#include <iostream>

#include "game.h"



Game::Game(Board board, Level level) : _board(board), _level(level){
    this->_board = Board(_level.getRows(), _level.getCols());
}

void Game::renderBoard(){
    this->_board.fillBoard(this->_level.getMap());
}


