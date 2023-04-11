#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "board.h"
#include "level.h"

class Game{
    Board _board;
    Level _level;

public:
    Game(Board &board, Level &level);
    Board getBoard();
    void renderBoard();
    void play();
    bool isGameOver();
    void nextLevel();
    void move(Position position, Direction direction);
};

#endif // GAME_H
