#include "controller.h"


Controller::Controller(Game& game, View& view) : _game(game), _view(view){
}

void Controller::start(){
    this->_view.WelcomeMessage();
    std::string i = this->_view.askInput();
    if(i == "y"){
        this->_game.renderLastBoard();
    } else {
        this->_game.renderBoard();
    }
    this->_game.getBoard().updateMovableItems();

    this->_view.printLevel(_game.getLevel());
    this->_view.printBoard(this->_game);
    while (!this->_game.isGameOver()) {
        std::string d = this->_view.askInput();
        if(d == "z"){
            this->_game.move(Direction::UP);
        }else if(d == "q"){
            this->_game.move(Direction::LEFT);
        }else if(d == "d"){
            this->_game.move(Direction::RIGHT);
        }else if(d == "s"){
            this->_game.move(Direction::DOWN);
        }else if(d == "o"){
            this->_game.saveGame();
        }else if(d == "u"){
            this->_game.undo();
        }else if(d == "r"){
            this->_game.restartLevel();
            this->_game.renderBoard();
        }else if(d == "h"){
            this->_view.printHelp();
            continue;
        }else if(d == "x"){
            this->_view.printBye();
            exit(1);
        }
        if(_game.getBoard().isWin()){
            _game.nextLevel();
            this->_game.renderBoard();
        }

        this->_game.getBoard().updateMovableItems();

        this->_view.printLevel(_game.getLevel());
        this->_view.printBoard(this->_game);

    }
    _view.printGameOver();
}
