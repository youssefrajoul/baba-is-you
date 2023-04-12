#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Level{
    int _level;
    vector<vector<string>> _map;
public:
    Level(int level);
    Level() = default;
    std::vector<vector<std::string>> getMap();
    int getRows();
    int getCols();
};

#endif // LEVEL_H
