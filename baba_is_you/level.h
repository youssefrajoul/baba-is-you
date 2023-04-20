#ifndef LEVEL_H
#define LEVEL_H
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
    int getRows();
    int getCols();
};

#endif // LEVEL_H
