#ifndef VIEW_H
#define VIEW_H




#include "../game.h"

class View{
public:
    View();
    void WelcomeMessage();
    void printBoard(Game& game);
    std::string askDirection();
    void printGameOver();
};

#endif // VIEW_H
