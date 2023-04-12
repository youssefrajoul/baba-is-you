#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

#include "../view/view.h"
#include "../game.h"

class Controller{
    Game _game;
    View _view;
public:
    Controller(Game& _game, View& _view);
    Controller() = default;
    void start();
    void play();
};

#endif // CONTROLLER_H
