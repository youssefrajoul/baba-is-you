#ifndef GAME_H
#define GAME_H


#include "board.h"
#include "level.h"


class Game{
    Board _board;
    Level _level;
public:
    Game();
    Board& getBoard();
    void renderBoard();
    void restartLevel();
    bool isGameOver();
    void nextLevel();
    void move(Direction direction);
    bool pushItems(Board& borde,Position& pos, Direction dir);

};

#endif // GAME_H
