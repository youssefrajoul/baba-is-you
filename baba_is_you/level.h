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
    //TODO documentation
    std::pair<Type, Status> translateFile(std::string word);
    int getRows();
    int getCols();
    int getLevelNumber();
    void writeLevel(std::vector<vector<std::string>> board);
};

#endif // LEVEL_H
