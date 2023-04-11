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

void Game::move(Position position, Direction direction){
    //TO do later
    bool isInside = this->_board.isInside(position);
    if(isInside){
         throw invalid_argument("position out of band");
    }
        if(direction == Direction::UP){
            if(this->_board.getBoard().at(position.getX()).at(position.getY()).getTopItem().getStatus() == Status::MOVE){

            }

        }

}
