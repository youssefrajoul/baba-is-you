#include "gui.h"

Gui::Gui(Game &game,QWidget * parent): QWidget{parent}, _game{game}{
    _qboard= new QBoard(_game);
    _window= new QHBoxLayout();
    setWindowIcon(QIcon("./resource/img/images/baba.png"));
    setWindowTitle("Welcome on Baba Is You");
    show();
}

void Gui::displayStartWindow() {
    _startWindow = new QStartWindow(this);
    _window->addWidget(_startWindow);
    _window->setAlignment(Qt::AlignCenter);
    setLayout(_window);
    //show();
    //connect(_startWindow, SIGNAL(started(QString)), this, SLOT(addLevel(QString)));
    //connect(_startWindow->get_start(),SIGNAL(clicked()),this,&Gui::displayBoards());
}


//TODO refaire cette methode
void Gui::update(Observable* observable){
   // Game* game = static_cast<Game*>(observable);
    //printBoard(*game);
    displayBoards();
}

void Gui::displayBoards(){
    _qboard->updateBoard();
    _window->addLayout(_qboard->getGrid());
   _window->setAlignment(Qt::AlignCenter);
    setLayout(_window);
}

void Gui::updateBoard(){
    delete _qboard;
    _qboard = new QBoard(_game);
    _window->addLayout(_qboard->getGrid());
    setLayout(_window);
}

void Gui::keyPressEvent(QKeyEvent *event){
      std::cout<<"Left"<<std::endl;
    switch(event->key()){
    case Qt::Key_Left :
        _game.move(Direction::LEFT);
        updateBoard();
        std::cout<<"Left"<<std::endl;
        break;
    case Qt::Key_Right :
        _game.move(Direction::RIGHT);
        std::cout<<"Right"<<std::endl;
        break;
    case Qt::Key_Up :
        _game.move(Direction::UP);
        std::cout<<"Up"<<std::endl;
        break;
    case Qt::Key_Down :
        _game.move(Direction::DOWN);
        std::cout<<"Down"<<std::endl;
        break;
    case Qt::Key_Z :
        _game.undo();
        break;
    case Qt::Key_R :
        _game.restartLevel();
        break;
    case Qt::Key_Escape :
        this->close();
        break;
    }
    QWidget::keyPressEvent(event);

}


