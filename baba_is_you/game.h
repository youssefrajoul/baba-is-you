#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "level.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
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
    int getLevel();
    /**
     * @brief renderBoard, Gets items from level
     * and put it on the board.
     */
    void renderBoard();
    /**
     * @brief renderLastBoard, Gets items from the last progress
     * and put it on the board.
     */
    void renderLastBoard();
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
    /**
     * @brief undo, Undo the last movement made
     * by the player.
     */
    void undo();
    /**
     * @brief saveGame, saves the progress of the player
     */
    void saveGame();
};

#endif // GAME_H
