#ifndef BOARD_H
#define BOARD_H

#include "square.h"
#include "position.h"
#include "item.h"
#include "direction.h"
#include <vector>

class Board{
    const int _ROWS;
    const int _COLS;
    std::vector<std::vector<Square>> board;
//    std::vector<Observer> observers;
public:
    Board();
    void setItem(Item item, Position pos);
    Item getItem(Position pos);
    void removeItem(Position pos);
    void checkNextPos(Direction dir);
};

#endif // BOARD_H
