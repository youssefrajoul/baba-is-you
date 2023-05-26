#include "../view/qcontroller.h"

QController::QController(Game & game,Gui* view):_game(game),_view(view){
}

void QController::startGame(){
    this->_view->displayStartWindow();
}


