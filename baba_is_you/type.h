#ifndef TYPE_H
#define TYPE_H
/**
 * @brief The Type enum, represent the
 * types of an item
 */
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
    TEXT_BEST = 'o',
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

#endif // TYPE_H
