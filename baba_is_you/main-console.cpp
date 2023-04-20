#include "controller/controller.h"

int main()
{

    Game game;
    View view;
    Controller controller = Controller(game, view);
    controller.start();
    return 0;
}



