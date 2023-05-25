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
//    QPixmap backgroundImage("./resource/img/images/backg.jpg");
//    QString styleSheet = QString("QWidget { background-image: url(./resource/img/images/backg.jpg); }").arg(backgroundImage.toImage().scaled(this->size()).width(), backgroundImage.toImage().scaled(this->size()).height());

//    _logo->setStyleSheet(styleSheet);


    connect(_start,&QPushButton::clicked, this, &QStartWindow::start);
}

Gui *QStartWindow::getParent(){
    return this->_parent;
}


void QStartWindow::start(){
    this->hide();
   // QView * itemView = qobject_cast<QView*>(parent());
    getParent()->displayBoards();
    //std::cout << "test test "   << std::endl;
}


QPushButton * QStartWindow::get_start(){
    return this->_start;
}
