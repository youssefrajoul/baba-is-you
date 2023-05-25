#include "../view/qcontroller.h"

QController::QController(Game game,Gui* view):_game{game},_view{view}{}

  void QController::play(){
      this->_game.attach(_view);
//      this->_game.renderBoard();
//      this->_game.updateMovableItems();
      this->_game.updateMovableItems();
      this->_view->displayStartWindow();

     // this->_view->displayBoards(_game);
//       while (!this->_game.isGameOver()) {

//       }


    }
