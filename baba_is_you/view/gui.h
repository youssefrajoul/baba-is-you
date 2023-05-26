#ifndef GUI_H
#define GUI_H
#include "game.h"
#include <QWidget>
#include "startWindow.h"
#include "qboard.h"
#include <QKeyEvent>

class Gui : public QWidget, public Observer{
    Game &_game;
    QStartWindow * _startWindow;
    QHBoxLayout * _window;
    QBoard * _qboard;

public:
    explicit Gui(Game &game, QWidget * parent = nullptr);
    void displayStartWindow();
    void displayBoards();
    void update(Observable * observable) override;
    void updateBoard();
    void displayLastBoards();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // GUI_H

