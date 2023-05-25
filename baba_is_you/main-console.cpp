#include "controller/controller.h"
//#include "test/test.h"


int main()
{
//    run_Tests();
    Game game;
    View view;
    Controller controller = Controller(game, view);
    controller.start();
    return 0;
}


//Bug 1: in the first level when wall is you and you try to move the wall down you lose cause BABA is under wall_text
