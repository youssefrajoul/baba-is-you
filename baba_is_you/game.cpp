#include "game.h"

int lvl = 2;

Game::Game() {
    this->_level = Level(lvl);
    this->_board = Board(_level);
}

Board& Game::getBoard(){
    return this->_board;
}
void Game::renderBoard(){
    this->_board.fillBoard(this->_level.getMap());
}
void Game::move(Direction direction){ 
    for (Item& item : this->_board.getMovables()){
        Position oldPos = item.getPosition();
        Position nextPos = item.getPosition().nextPos(direction);

        if(this->_board.isInside(nextPos)){
            //deplacement simple
            if(this->_board.isEmpty(nextPos)){
                item.setPosition(nextPos);
                this->_board.setItem(item, nextPos);
                this->_board.getArray()[oldPos.getX()][oldPos.getY()].removeTopItem();

            }else if(this->_board.isWinable(nextPos)){
                _board.setWin(true);
            }
            else if(_board.isPushable(nextPos)){
                // pousser les item
                bool contenu;
                while(!_board.isEmpty(nextPos) && !_board.isWinable(nextPos)){
                    contenu = pushItems(this->_board,oldPos,direction);
                    if(!contenu){
                        break;

                    }

                }
                //pour retester s'il y a un win
                if(this->_board.isWinable(nextPos)){
                                _board.setWin(true);
                            }
                if(_board.isEmpty(nextPos)){
                    item.setPosition(nextPos);
                    this->_board.setItem(item, nextPos);
                    this->_board.getArray()[oldPos.getX()][oldPos.getY()].removeTopItem();

                }

            }else if(_board.isKiller(nextPos)){
              this->_board.getArray()[oldPos.getX()][oldPos.getY()].removeTopItem();
               for(int i = 0; i < _board.getMovables().size();i++){
                   if(_board.getMovables().at(i) == item){
                        _board.getMovables().erase(_board.getMovables().begin() + i);
                   }
               }

            }else if(_board.isSink(nextPos)) {
                this->_board.getArray()[nextPos.getX()][nextPos.getY()].removeTopItem();
                this->_board.getArray()[oldPos.getX()][oldPos.getY()].removeTopItem();
                 for(auto i = 0; i < _board.getMovables().size();i++){
                     if(_board.getMovables().at(i) == item){
                          _board.getMovables().erase(_board.getMovables().begin() + i);
                     }
                 }



            }

        } 
    }
}


bool Game::pushItems(Board& board, Position &pos, Direction dir){
    bool contenu {true};
    Position nextPos = pos.nextPos(dir);
    if(_board.isInside(nextPos.nextPos(dir))){
         std::cout << "isInside : true" << std::endl;
        if(board.isPushable(nextPos)){
          contenu = pushItems(board,nextPos,dir);

        }else if (_board.isEmpty(nextPos) || _board.isWinable(nextPos)){
                  Item item = board.getItemAt(pos);
                  item.setPosition(nextPos);
                  board.setItem(item,nextPos);
                  board.getArray().at(pos.getX())
                          .at(pos.getY()).removeTopItem();

        }else if(_board.isSink(nextPos)){
            this->_board.getArray()[nextPos.getX()][nextPos.getY()].removeTopItem();
            this->_board.getArray()[pos.getX()][pos.getY()].removeTopItem();


        }else if(_board.isKiller(nextPos)){
            this->_board.getArray()[pos.getX()][pos.getY()].removeTopItem();


        }else{
            contenu = false;
                    }

   }else{
        contenu = false;
                }

    return contenu;

}

bool Game::isGameOver(){

  return _board.getMovables().empty();

}
void Game::restartLevel(){
    this->_level = Level(lvl);
    this->_board = Board(_level);

}

void Game::nextLevel(){
    this->_level = Level(++lvl);
    this->_board = Board(_level);

}
