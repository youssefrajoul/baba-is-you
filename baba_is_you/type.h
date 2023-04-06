#ifndef TYPE_H
#define TYPE_H

#include <iostream>

enum class Type : char {
    WALL = 'W',TEXT_WALL = 'T',
    BABA = 'B',TEXT_BABA = 'T',
    /*YOU,*/TEXT_YOU = 'T',
    LAVA = 'L',TEXT_LAVA = 'T',
    WATER = 'T',TEXT_WATER = 'T',
    ROCK = 'R',TEXT_ROCK = 'T',
    ICE = 'I',TEXT_ICE = 'T',
    GRASS = 'G',TEXT_GRASS = 'T',
    SKULL = 'S',TEXT_SKULL = 'T',
    FLAG = 'F',TEXT_FALG = 'T',
    TEXT_HOT = 'T',
    IS = 'I',
    EMPTY = 'E',TEXT_EMPTY = 'T',
};


#endif // TYPE_H
