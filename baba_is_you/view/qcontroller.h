#ifndef QCONTROLLER_H
#define QCONTROLLER_H
#include "gui.h"
class QController{
    Game _game;
    Gui * _view;

public:
    QController(Game game, Gui *view);
    void play();


};

#endif // QCONTROLLER_H
