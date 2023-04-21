#ifndef LEVEL_H
#define LEVEL_H

#include "type.h"
#include "status.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * @brief The Level class, represent
 * a level in the game.
 */
class Level{
    int _level;
    vector<vector<string>> _map;
public:
    Level(int level);
    Level() = default;
    /**
     * @brief getMap, to read the map of
     * the level
     * @return a vector of string
     */
    std::vector<vector<std::string>> getMap();
    /**
     * @brief translateFile, this method translate words of the file level
     * to real items.
     * @param word is a string from the file
     * @return pair of type with default status for each type
     */
    std::pair<Type, Status> translateFile(std::string word);
    int getRows();
    int getCols();
    int getLevelNumber();
    /**
     * @brief writeLevel, writes lines in a file
     * if the file doesn't exist it creates new one.
     * @param board is a 2D vector of the items of the board translated
     * to strings.
     */
    void writeLevel(std::vector<vector<std::string>> board);
};

#endif // LEVEL_H
