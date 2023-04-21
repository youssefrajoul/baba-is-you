#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "level.h"
#include <stack>

/**
 * @brief The Game class, represent the logic
 * of the game.
 */
class Game{
    /**
     * @brief _board, the board of the game.
     */
    Board _board;
    /**
     * @brief _level, the level of the game
     */
    Level _level;
    std::stack<Board> _boards;
public:
    Game();
    Board& getBoard();
    //TODO documentation
    void renderBoard();
    /**
     * @brief restartLevel, to restate the level.
     */
    void restartLevel();
    /**
     * @brief isGameOver, to test if the game
     * is over .
     * @return
     */
    bool isGameOver();
    /**
     * @brief nextLevel, to start the next level
     */
    void nextLevel();
    /**
     * @brief moven, this method moves all items
     * in the vector 'movableItem' into a given direction
     * @param direction, the given directions
     */
    void move(Direction direction);
    /**
     * @brief pushItems, this helper recursive function push
     * all the pushable items into a given dirction
     * @param borde, the board of the game.
     * @param pos, given position
     * @param dir, given dirction
     * @return
     */
    bool pushItems(Board& borde,Position& pos, Direction dir);
    void undo();
};

#endif // GAME_H
