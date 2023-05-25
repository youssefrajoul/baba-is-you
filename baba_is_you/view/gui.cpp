#include "gui.h"

Gui::Gui(Game &game):/*QWidget{parent},*/ _game{game}{
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
    //connect(_startWindow, SIGNAL(started(QString)), this, SLOT(addLevel(QString)));
    //connect(_startWindow->get_start(),SIGNAL(clicked()),this,&Gui::displayBoards());
}


void Gui::displayBoards(){
    _qboard= new QBoard(_game);
    _startWindow->close();
    _qboard->updateBoard();
    _window->addLayout(_qboard->getGrid());
    _window->setAlignment(Qt::AlignCenter);
    setLayout(_window);
}


