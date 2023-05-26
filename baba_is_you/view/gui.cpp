#include "gui.h"

Gui::Gui(Game &game,QWidget * parent): QWidget{parent}, _game{game}{
    _qboard= new QBoard(_game);
    _window= new QHBoxLayout();
    setWindowIcon(QIcon("./resource/img/images/baba.png"));
    setWindowTitle("Welcome on Baba Is You");
    show();
    setFocusPolicy(Qt::StrongFocus);
}

void Gui::displayStartWindow() {
    _startWindow = new QStartWindow(this);
    _window->addWidget(_startWindow);
    _window->setAlignment(Qt::AlignCenter);
    setLayout(_window);
}



void Gui::update(Observable *observable){
//     *observable is used in Console but not in GUI
    Game* game = static_cast<Game*>(observable);
    std::cout << game->isGameOver() << std::endl;
    updateBoard();
}

void Gui::displayBoards(){
    _game.renderBoard();
    _qboard->updateBoard();
    _window->addLayout(_qboard);
    _window->setAlignment(Qt::AlignCenter);
    setLayout(_window);
    this->_game.updateMovableItems();
}

void Gui::updateBoard(){
    if(_game.getBoard().isWin()){
        _game.nextLevel();
        this->_game.renderBoard();
    }
    _window->removeItem(_qboard);
    delete _qboard;
    _qboard = new QBoard(_game);
    _qboard->updateBoard();
    _window->addLayout(_qboard);
}

void Gui::displayLastBoards(){
    _game.renderLastBoard();
    _qboard->updateBoard();
    _window->addLayout(_qboard);
    _window->setAlignment(Qt::AlignCenter);
    setLayout(_window);
    this->_game.updateMovableItems();
}

void Gui::keyPressEvent(QKeyEvent *event){

    switch(event->key()){
    case Qt::Key_Left :
        std::cout<<"Left"<<std::endl;
        _game.move(Direction::LEFT);
        break;
    case Qt::Key_Right :
        std::cout<<"Right"<<std::endl;
        _game.move(Direction::RIGHT);
        break;
    case Qt::Key_Up :
        std::cout<<"Up"<<std::endl;
        _game.move(Direction::UP);
        break;
    case Qt::Key_Down :
        std::cout<<"Down"<<std::endl;
        _game.move(Direction::DOWN);
        break;
    case Qt::Key_Z :
        _game.undo();
        break;
    case Qt::Key_R :
        _game.restartLevel();
        break;
    case Qt::Key_S :
            _game.saveGame();
            break;
    case Qt::Key_Escape :
        this->close();
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
    _game.updateMovableItems();
}


