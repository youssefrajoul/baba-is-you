#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Level{
    int level;
    vector<vector<string>> map;

public:
    Level(int level);
    std::vector<vector<string>> getMap();
};

#endif // LEVEL_H
