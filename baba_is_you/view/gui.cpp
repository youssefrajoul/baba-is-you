#include "gui.h"

QView::QView(Game &game, QWidget *parent):QWidget{parent}, _game{game}{
     _window= new QHBoxLayout();

    displayStartWindow();
   //  displayBoards();
    setWindowIcon(QIcon("./resource/img/images/baba.png"));
    setWindowTitle("Welcome on Baba Is You");
    show();
}

void QView::displayStartWindow() {
    _startWindow = new QStartWindow(this);
    _window->addWidget(_startWindow);
    _window->setAlignment(Qt::AlignCenter);
    setLayout(_window);
   //connect(_startWindow, SIGNAL(started(QString)), this, SLOT(addLevel(QString)));
  //  connect(_startWindow->get_start(),SIGNAL(clicked()),this,&QView::displayBoards());
}


void QView::displayBoards(){
    _qboard= new QBoard(_game);
    _startWindow->close();
    _qboard->updateBoard();
    _window->addLayout(_qboard->getGrid());
    _window->setAlignment(Qt::AlignCenter);
    setLayout(_window);
}


