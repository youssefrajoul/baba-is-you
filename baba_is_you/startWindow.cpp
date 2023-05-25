#include "startWindow.h"

QStartWindow::QStartWindow(QWidget * parent) : QWidget {parent} {
    QVBoxLayout * menu = new QVBoxLayout();
    _logo = new QLabel("Baba is You");
    QFontDatabase::addApplicationFont(("./resource/fonts/Quicksand.otf"));
    QFont font ("Quicksand", 50, QFont::Bold);
    _logo->setFont(font);
    _logo->setAlignment(Qt::AlignCenter);
    menu->addWidget(_logo);
    _start = new QPushButton("Launch");
    menu->addWidget(_start);
    _last = new QPushButton("launch saved level");
    menu->addWidget(_last);
    setLayout(menu);
    adjustSize();

//    QPixmap backgroundImage("./resource/img/images/backg.jpg");
//    QString styleSheet = QString("QWidget { background-image: url(./resource/img/images/backg.jpg); }").arg(backgroundImage.toImage().scaled(this->size()).width(), backgroundImage.toImage().scaled(this->size()).height());

//    _logo->setStyleSheet(styleSheet);


//    connect(_start,SIGNAL(clicked()), this, SLOT(start()));
}


void QStartWindow::start(){
    this->close();
}


QPushButton * QStartWindow::get_start(){
    return this->_start;
}
