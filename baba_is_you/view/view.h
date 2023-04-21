#ifndef VIEW_H
#define VIEW_H




#include "../game.h"

class View{
public:
    View();
    void WelcomeMessage();
    void printBoard(Game& game);
    void printHelp();
    std::string askInput();
    void printLevel(int level);
    void printBye();
    void printGameOver();
};

#endif // VIEW_H
