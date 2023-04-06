#ifndef BOARD_H
#define BOARD_H

#include "square.h"
#include "position.h"
#include "item.h"
#include "direction.h"
#include <vector>
#include <array>
#include <optional>

class Board{
    int _rows;
    int _cols;
    std::array<std::array<std::optional<Square>, 18>, 18> _array;
//    std::vector<Observer> observers;
public:
    Board(int rows, int cols);
    void fillBoard(std::vector<std::vector<std::string>> items);
    void setItem(Item &item, Position &pos);
    Item getItem(Position pos);
    void removeItems(Position pos);
    Status nextPosStatus(Position pos, Direction dir);
    Type nextPosType(Position pos, Direction dir);
    void printBoard();
};

#endif // BOARD_H
