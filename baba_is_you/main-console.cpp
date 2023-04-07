#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <vector>
#include <map>

using namespace std;

#include "game.h"
#include "board.h"
#include "level.h"

int main()
{
    Level level(2);
    Board board(level.getRows(), level.getCols());
    Game game(board, level);
    game.renderBoard();
    game.getBoard().printBoard();
    return 0;
}

