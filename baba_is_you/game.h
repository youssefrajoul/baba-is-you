#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "board.h"
#include "level.h"


class Game{
    Board _board;
    Level _level;
public:
    Game();
    Board& getBoard();
    void renderBoard();
    void play();
    bool isGameOver();
    void nextLevel();
    void move(Direction direction);
    void pushItems(Board& borde,Position& pos, Direction dir);

};

#endif // GAME_H
