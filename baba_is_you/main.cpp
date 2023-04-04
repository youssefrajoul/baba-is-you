#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "game.h"
#include "board.h"
#include "level.h"

int main()
{
    std::cout << "test";
    Level level(2);
    Board board(level.getRows(), level.getCols());
    Game game(board, level);
    game.renderBoard();
    board.printBoard();
    return 0;
}
