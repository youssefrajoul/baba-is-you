#ifndef GUI_H
#define GUI_H
#include "game.h"
#include <QWidget>
#include "startWindow.h"
#include "qboard.h"
#include <QKeyEvent>
//#include "observer/observer.h"
class Gui : public QWidget, public Observer{
    Game &_game;
    QStartWindow * _startWindow;
    QHBoxLayout * _window;
    QBoard * _qboard;


//private slots:

//    void displayBoard();

public:
    explicit Gui(Game &game, QWidget * parent = nullptr);
    void displayStartWindow();
    void displayBoards();
    void update(Observable * observable) override;
    void updateBoard();


protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // GUI_H

