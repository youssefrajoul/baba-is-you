#include "../view/qcontroller.h"

QController::QController(Game game,Gui* view):_game{game},_view{view}{
    QStartWindow* startButton = new QStartWindow(view);
    connect(startButton, &QStartWindow::startClicked, this, &QController::play);
}

void QController::startGame(){
    this->_view->displayStartWindow();
    this->_game.attach(_view);
}

void QController::play(){
    //      this->_game.renderBoard();
          this->_game.updateMovableItems();

    std::cout << "test test" << std::endl;
    //      this->_game.updateMovableItems();

    // this->_view->displayBoards(_game);
    //       while (!this->_game.isGameOver()) {

    //       }


}

