#include "controller.h"


Controller::Controller(Game& game, View& view) : _game(game), _view(view){
    std::cout << "Controller Object Creation" << std::endl;
}

void Controller::start(){
    this->_game.renderBoard();
    this->_view.printBoard(this->_game);
    int i = 0;
    while (i < 2) {
        this->_game.getBoard().findIsItems();
        this->_game.getBoard().updateItemsStatus();
        this->_game.getBoard().updateMovableItems();
        this->_game.move(Direction::LEFT);
        this->_game.renderBoard();
        this->_view.printBoard(this->_game);
        i++;
    }
}
