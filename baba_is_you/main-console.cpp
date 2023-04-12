#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <vector>
#include <map>

using namespace std;

#include "controller/controller.h"

int main()
{
    Game game;
    View view;
    Controller controller = Controller(game, view);
    controller.start();
    return 0;
}

