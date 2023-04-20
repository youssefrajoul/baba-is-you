#ifndef TYPE_H
#define TYPE_H

#include <iostream>

enum class Type : char {
    WALL = 'W',
    BABA = 'B',
    LAVA = 'L',
    WATER = 'T',
    ROCK = 'R',
    ICE = 'I',
    GRASS = 'G',
    SKULL = 'S',
    FLAG = 'F',
    EMPTY = ' ',
    METAL = 'M',
    END = '*',
    TEXT_IS = 'i',
    TEXT_WIN = 'w',
    TEXT_PUSH = 'p',
    TEXT_STOP = 's',
    TEXT_YOU = 'y',
    TEXT_SINK = 'n',
    TEXT_KILL = 'k',
    TEXT_BEST = 'b',
    TEXT_WALL = 'a',
    TEXT_BABA = 'b',
    TEXT_LAVA = 'l',
    TEXT_WATER = 't',
    TEXT_ROCK = 'r',
    TEXT_ICE = 'c',
    TEXT_GRASS = 'g',
    TEXT_SKULL = 's',
    TEXT_FLAG = 'f',
    TEXT_EMPTY = 'e'
};

//const std::map<Type, std::string> type_names = {
//    {Type::WALL, "WA"},
//    {Type::BABA, "BA"},
//    {Type::LAVA, "LA"},
//    {Type::WATER, "WT"},
//    {Type::ROCK, "RO"},
//    {Type::ICE, "IC"},
//    {Type::GRASS, "GR"},
//    {Type::SKULL, "SK"},
//    {Type::FLAG, "FL"},
//    {Type::EMPTY, "EM"},
//    {Type::METAL, "ME"},
//    {Type::END, "**"},
//    {Type::TEXT_IS, "is"},
//    {Type::TEXT_WIN, "wi"},
//    {Type::TEXT_PUSH, "pu"},
//    {Type::TEXT_STOP, "st"},
//    {Type::TEXT_YOU, "yo"},
//    {Type::TEXT_SINK, "si"},
//    {Type::TEXT_BEST, "be"},
//    {Type::TEXT_WALL, "wa"},
//    {Type::TEXT_BABA, "ba"},
//    {Type::TEXT_LAVA, "la"},
//    {Type::TEXT_WATER, "wa"},
//    {Type::TEXT_ROCK, "ro"},
//    {Type::TEXT_ICE, "ic"},
//    {Type::TEXT_GRASS, "gr"},
//    {Type::TEXT_SKULL, "sk"},
//    {Type::TEXT_FALG, "fl"},
//    {Type::TEXT_EMPTY, "em"}
//};




#endif // TYPE_H
