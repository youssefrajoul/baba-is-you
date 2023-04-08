#ifndef BOARD_H
#define BOARD_H

#include "square.h"
#include "type.h"
#include "position.h"
#include "item.h"
#include "direction.h"
#include <vector>
#include <array>

class Board{
    int _rows;
    int _cols;
    std::array<std::array<Square, 20>, 20> _array;
//    std::vector<Observer> observers;
public:
    Board(int rows, int cols);
    std::array<std::array<Square,20>,20> &getBoard();
    void fillBoard(std::vector<std::vector<std::string>> items);
    std::pair<Type, Status> getType(std::string word);
    void setItem(Item &item, Position &pos);
    Item getItem(Position pos);
    void removeItems(Position pos);
    Status nextPosStatus(Position pos, Direction dir);
    Type nextPosType(Position pos, Direction dir);
    void printBoard();
};

#endif // BOARD_H
