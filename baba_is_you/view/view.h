#ifndef VIEW_H
#define VIEW_H

#include <iostream>

#include "../game.h"

class View{
public:
    View();
    void WelcomeMessage();
    void printBoard(Game& game);
};

#endif // VIEW_H
