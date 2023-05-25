#ifndef GUI_H
#define GUI_H
#include "game.h"
#include <QWidget>
#include "startWindow.h"
#include "qboard.h"
#include "observer/observer.h"
class QView : public QWidget , public Observer{
    Game &_game;
    QStartWindow * _startWindow;
    QHBoxLayout * _window;
    QBoard * _qboard;

//private slots:

//    void displayBoard();

public:
    explicit QView(Game &game,QWidget *parent = nullptr);
    void displayStartWindow();
    void displayBoards();
};

#endif // GUI_H
