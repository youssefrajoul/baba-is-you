#include <iostream>

#include "game.h"


Game::Game() {
   // std::cout << "Game Object creation" << std::endl;
    this->_level = Level(0);
    this->_board = Board(_level);
}

Board& Game::getBoard(){
    return this->_board;
}


void Game::renderBoard(){
    this->_board.fillBoard(this->_level.getMap());
}

void Game::move(Direction direction){
    //TO do later

    // Printing elements of an array using
    // foreach loop
    std::cout << this->_board.getMovables().size()<< std::endl;
    std::cout <<  static_cast<char>(this->_board.getMovables().back().getType())<< std::endl;
    std::cout << this->_board.getMovables().back().getPosition().getX();
     std::cout << this->_board.getMovables().back().getPosition().getY()<< std::endl;
    for (Item& item : this->_board.getMovables()){


        Position oldPos = item.getPosition();
        std::cout << oldPos.getY() << std::endl;
        Position nextPos =item.getPosition().nextPos(direction);
        if(this->_board.isInside(nextPos)){
            //deplacement simple
            if(this->_board.isEmpty(nextPos)){
                this->_board.setItem(item, nextPos);
                item.setPosition(nextPos);
                this->_board.getArray()[oldPos.getX()][oldPos.getY()].removeTopItem();
            }else{
                // pousser les item
                pushItems(this->_board,oldPos,direction);

            }



        }
        /*    if(direction == Direction::UP){
                if(this->_board.getBoard().at(position.getX())
                    .at(position.getY()).getTopItem()
                    .getStatus() == Status::PUSH){


                }

            }*/
    }
    std::cout << this->_board.getMovables().back().getPosition().getX();
     std::cout << this->_board.getMovables().back().getPosition().getY()<< std::endl;

}


void Game::pushItems(Board& board,Position pos, Direction dir){
    //while(board.isPushable(pos)){
    Position nextPos = pos.nextPos(dir);
    if(board.isPushable(nextPos)){
        pushItems(board,nextPos,dir);
    }else{
        Item item = board.getItemAt(pos);
        board.setItem(item,nextPos);
        item.setPosition(nextPos);
        board.getArray().at(pos.getX())
                .at(pos.getY()).removeTopItem();
    }

    // }
}

bool Game::isGameOver(){

    //TO DO later
    return true;
}
