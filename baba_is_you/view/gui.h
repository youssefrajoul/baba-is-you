#ifndef GUI_H
#define GUI_H
#include "game.h"
#include <QWidget>
#include "startWindow.h"
#include "qboard.h"
#include "observer/observer.h"
class Gui : public QWidget{
    Game &_game;
    QStartWindow * _startWindow;
    QHBoxLayout * _window;
    QBoard * _qboard;


//private slots:

//    void displayBoard();

public:
    explicit Gui(Game &game/*,QWidget *parent*/);
    void displayStartWindow();
    void displayBoards();
};

#endif // GUI_H
