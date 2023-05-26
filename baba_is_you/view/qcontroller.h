#ifndef QCONTROLLER_H
#define QCONTROLLER_H
#include "gui.h"
class QController : public QWidget {
    Q_OBJECT
    Game _game;
    Gui * _view;

public:
    QController(Game &game, Gui *view);
    void startGame();

};

#endif // QCONTROLLER_H
