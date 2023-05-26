#include "game.h"

int lvl = 0;

Game::Game() {
    this->_level = Level(lvl);
    this->_board = Board(_level);
    this->_boards = stack<Board>();
}

Board& Game::getBoard(){
    return this->_board;
}
int Game::getLevel(){
    return this->_level.getLevel();
}
void Game::renderBoard(){
    this->_board.fillBoard(this->_level.getMap());
    _boards.push(_board);
}
void Game::renderLastBoard(){
    this->_level = Level(1999);
    this->_board = Board(_level);
    this->_board.fillBoard(this->_level.getMap());
}

// TODO bug detected: if movable items are more than one item the movement to the right doesn't function properly
void Game::move(Direction direction){
    // TODO, discuss the next line with tareq
    _boards.push(_board);
    for (Item& item : this->_board.getMovables()){
        Position oldPos = item.getPosition();
        Position nextPos = item.getPosition().nextPos(direction);

        if(this->_board.isInside(nextPos)){
            //deplacement simple
            if(this->_board.getItemAt(nextPos).isEmpty()){
                item.setPosition(nextPos);
                this->_board.setItem(item, nextPos);
                this->_board.getArray()[oldPos.getX()][oldPos.getY()].removeTopItem();

            }else if(this->_board.getItemAt(nextPos).isWinable()){
                _board.setWin(true);
            }
            else if(_board.getItemAt(nextPos).isPushable() || _board.getItemAt(nextPos).isMovable()){
                // pousser les item
                bool contenu;
                while(!_board.getItemAt(nextPos).isEmpty() && !_board.getItemAt(nextPos).isWinable()){
                    contenu = pushItems(this->_board,oldPos,direction);
                    if(!contenu){
                        break;
                    }
                }
                //pour retester s'il y a un win
                if(this->_board.getItemAt(nextPos).isWinable()){
                    _board.setWin(true);
                }
                if(_board.getItemAt(nextPos).isEmpty()){
                    item.setPosition(nextPos);
                    this->_board.setItem(item, nextPos);
                    this->_board.getArray()[oldPos.getX()][oldPos.getY()].removeTopItem();

                }
            }else if(_board.getItemAt(nextPos).isKiller()){
                this->_board.getArray()[oldPos.getX()][oldPos.getY()].removeTopItem();
                for(unsigned int i = 0; i < _board.getMovables().size();i++){
                    if(_board.getMovables().at(i) == item){
                        _board.getMovables().erase(_board.getMovables().begin() + i);
                    }
                }
            }else if(_board.getItemAt(nextPos).isSink()) {
                this->_board.getArray()[nextPos.getX()][nextPos.getY()].removeTopItem();
                this->_board.getArray()[oldPos.getX()][oldPos.getY()].removeTopItem();
                for(unsigned int i = 0; i < _board.getMovables().size();i++){
                    if(_board.getMovables().at(i) == item){
                        _board.getMovables().erase(_board.getMovables().begin() + i);
                    }
                }
            }

        }
    }
//    notifyObserver();
}

void Game::updateMovableItems(){
    getBoard().updateMovableItems();
    notifyObserver();
}


bool Game::pushItems(Board& board, Position &pos, Direction dir){
    bool contenu {true};
    Position nextPos = pos.nextPos(dir);
    if(_board.isInside(nextPos.nextPos(dir))){
        if(board.getItemAt(nextPos).isPushable() || board.getItemAt(nextPos).isMovable()){
            contenu = pushItems(board,nextPos,dir);

        }else if (_board.getItemAt(nextPos).isEmpty() || _board.getItemAt(nextPos).isWinable()){
            Item item = board.getItemAt(pos);
            item.setPosition(nextPos);
            board.setItem(item,nextPos);
            board.getArray().at(pos.getX())
                    .at(pos.getY()).removeTopItem();

        }else if(_board.getItemAt(nextPos).isSink()){
            this->_board.getArray()[nextPos.getX()][nextPos.getY()].removeTopItem();
            this->_board.getArray()[pos.getX()][pos.getY()].removeTopItem();


        }else if(_board.getItemAt(nextPos).isKiller()){
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
    this->_level = Level(getLevel());
    this->_board = Board(_level);
    // TODO, discuss with tareq
    cleanStack();
}

// TODO, discuss with tareq
void Game::cleanStack(){
    while (!_boards.empty()) {
        _boards.pop();
    }
}

void Game::nextLevel(){
    this->_level = Level(getLevel()+1);
    this->_board = Board(_level);
    cleanStack();
}

void Game::undo(){
    if(!_boards.empty()){
    this->_board = _boards.top();
        _boards.pop();
    }
}

void Game::saveGame(){
    std::vector<std::vector<std::string>> map;
    for (unsigned int i = 0; i < _board.getArray().size()-1; ++i) {
        for (unsigned int j = 0; j < _board.getArray()[i].size()-1; ++j) {
            Position pos(i, j);
            Type type = _board.getItemAt(pos).getType();
            std::string item;
            std::vector<std::string> words;
            switch (type) {
            case Type::WALL:
                item = "wall";
                break;
            case Type::TEXT_WALL:
                item = "text_wall";
                break;
            case Type::ROCK:
                item = "rock";
                break;
            case Type::TEXT_ROCK:
                item = "text_rock";
                break;
            case Type::METAL:
                item = "metal";
                break;
            case Type::FLAG:
                item = "flag";
                break;
            case Type::TEXT_FLAG:
                item = "text_flag";
                break;
            case Type::BABA:
                item = "baba";
                break;
            case Type::TEXT_BABA:
                item = "text_baba";
                break;
            case Type::TEXT_WIN:
                item = "win";
                break;
            case Type::TEXT_YOU:
                item = "you";
                break;
            case Type::TEXT_IS:
                item = "is";
                break;
            case Type::TEXT_STOP:
                item = "stop";
                break;
            case Type::TEXT_PUSH:
                item = "push";
                break;
            case Type::TEXT_BEST:
                item = "best";
                break;
            case Type::LAVA:
                item = "lava";
                break;
            case Type::TEXT_LAVA:
                item = "text_lava";
                break;
            case Type::WATER:
                item = "water";
                break;
            case Type::TEXT_WATER:
                item = "text_water";
                break;
            case Type::GRASS:
                item = "grass";
                break;
            case Type::TEXT_GRASS:
                item = "text_grass";
                break;
            default:
                continue;
            }
            words.push_back(item);
            words.push_back(std::to_string(i-1));
            words.push_back(std::to_string(j-1));
            map.push_back(words);
        }
    }
    this->_level.writeLevel(map);
}
