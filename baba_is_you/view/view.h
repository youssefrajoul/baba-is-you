#ifndef VIEW_H
#define VIEW_H




#include "../game.h"
#include "../observer/observer.h"

class View : public Observer{
public:
    View();
    void WelcomeMessage();
    void update(Observable* observable);
    void printBoard(Game& game);
    void printHelp();
    std::string askInput();
    void printLevel(int level);
    void printBye();
    void printGameOver();
};

#endif // VIEW_H
