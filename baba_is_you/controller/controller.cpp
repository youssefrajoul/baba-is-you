#include "controller.h"


Controller::Controller(Game& game, View& view) : _game(game), _view(view){
   // std::cout << "Controller Object Creation" << std::endl;
}

void Controller::start(){
    this->_game.renderBoard();
    this->_view.printBoard(this->_game);
    while (this->_game.isGameOver()) {
        this->_game.getBoard().findIsItems();
        this->_game.getBoard().updateItemsStatus();
        this->_game.getBoard().updateMovableItems();
        std::string d = this->_view.askDirection();
        if(d == "u"){
           this->_game.move(Direction::UP);
        }else if(d == "l"){
          this->_game.move(Direction::LEFT);
        }else if(d == "r"){
            this->_game.move(Direction::RIGHT);
        }else if(d == "d"){
            this->_game.move(Direction::DOWN);
        }

         this->_view.printBoard(this->_game);

    }

    //int i = 0;



        //this->_game.renderBoard();
        this->_view.printBoard(this->_game);
    //this->_game.move(Direction::LEFT);
  // this->_view.printBoard(this->_game);
      //  i++;
}
