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
    std::cout << "ppppppppppsssssss1" << std::endl;
    Game game(board, level);
    std::cout << "ppppppppppsssssss2" << std::endl;
    game.renderBoard();
    std::cout << "ppppppppppsssssss3" << std::endl;
    board.printBoard();
    return 0;
}

