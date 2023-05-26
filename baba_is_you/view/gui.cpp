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
    //show();
    //connect(_startWindow, SIGNAL(started(QString)), this, SLOT(addLevel(QString)));
    //connect(_startWindow->get_start(),SIGNAL(clicked()),this,&Gui::displayBoards());
}


//TODO refaire cette methode
void Gui::update(Observable* observable){
    // Game* game = static_cast<Game*>(observable);
    //printBoard(*game);
    //displayBoards();
    std::cout << "test from update" << std::endl;
}

void Gui::displayBoards(){
    _game.renderBoard();
    _qboard->updateBoard();
    _window->addLayout(_qboard->getGrid());
    _window->setAlignment(Qt::AlignCenter);
    setLayout(_window);
}

void Gui::updateBoard(){
    std::cout << "update board method" << std::endl;
    _window->removeItem(_qboard->getGrid());
    delete _qboard;
    _qboard = new QBoard(_game);
    _qboard->updateBoard();
    _window->addLayout(_qboard->getGrid());
    _window->setAlignment(Qt::AlignCenter);
    setLayout(_window);
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
    case Qt::Key_Escape :
        this->close();
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
    _game.updateMovableItems();
    updateBoard();
}


