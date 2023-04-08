#ifndef STATUS_H
#define STATUS_H

enum class Status : char{
    MOVE = 'M',
    PUSH = 'P',
    SINK = 'S',
    STOP = 'T',
    WIN = 'W',
    KILL = 'K',
    NOTHING = 'N'
};

#endif // STATUS_H
