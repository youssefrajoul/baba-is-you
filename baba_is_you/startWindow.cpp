#include "startWindow.h"
#include "view/gui.h"

QStartWindow::QStartWindow(Gui * parent) : _parent{parent}{
    QVBoxLayout * menu = new QVBoxLayout();
    _logo = new QLabel("Baba is You");
    QFontDatabase::addApplicationFont(("./resource/fonts/Quicksand.otf"));
    QFont font ("Quicksand", 50, QFont::Bold);
    _logo->setFont(font);
    _logo->setAlignment(Qt::AlignCenter);
    menu->addWidget(_logo);
    _start = new QPushButton("Start");
    menu->addWidget(_start);
    _last = new QPushButton("Start saved level");
    menu->addWidget(_last);
    setLayout(menu);
    adjustSize();

    connect(_start,&QPushButton::clicked, this, &QStartWindow::start);
    connect(_last,&QPushButton::clicked, this, &QStartWindow::startLast);
}

Gui *QStartWindow::getParent(){
    return this->_parent;
}

void QStartWindow::start(){
    this->hide();
   // QView * itemView = qobject_cast<QView*>(parent());
    getParent()->displayBoards();
//    emit startClicked();

    //std::cout << "test test "   << std::endl;
}

QPushButton * QStartWindow::get_start(){
    return this->_start;
}

void QStartWindow::startLast(){
    this->hide();
    getParent()->displayLastBoards();
}
