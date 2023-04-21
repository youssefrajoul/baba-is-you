#include "controller.h"


Controller::Controller(Game& game, View& view) : _game(game), _view(view){
}

void Controller::start(){
    this->_game.renderBoard();
    this->_game.getBoard().updateMovableItems();
    this->_view.printBoard(this->_game);
    while (!this->_game.isGameOver()) {
        std::string d = this->_view.askDirection();
        if(d == "z"){
            this->_game.move(Direction::UP);
        }else if(d == "q"){
            this->_game.move(Direction::LEFT);
        }else if(d == "d"){
            this->_game.move(Direction::RIGHT);
        }else if(d == "s"){
            this->_game.move(Direction::DOWN);
        }else if(d == "u"){
            this->_game.undo();
        }
        if(_game.getBoard().isWin()){
            _game.nextLevel();
            this->_game.renderBoard();
        }

        this->_game.getBoard().updateMovableItems();
        this->_view.printBoard(this->_game);

    }
    _view.printGameOver();
}
