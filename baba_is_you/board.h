#ifndef BOARD_H
#define BOARD_H

#include "square.h"
#include "type.h"
#include "position.h"
#include "item.h"
#include "direction.h"
#include "level.h"

#include <vector>
#include <array>
#include <map>
#include <variant>

class Board{
    int _rows;
    int _cols;
    Level _level;
    std::array<std::array<Square, 20>, 20> _array;
    std::map<std::variant<Type, Status>, Type> _itemsStatus;
    std::vector<Item> _isItems;
    std::vector<Item> _movableItems;
    //    std::vector<Observer> observers;
public:
    //    these methods need to be in order cause too much (new Class?)
    Board(Level& level);
    Board() = default;
    std::array<std::array<Square, 20>, 20>& getArray();
    void fillBoard(std::vector<std::vector<std::string>> items);
    std::pair<Type, Status> getTypeStatus(std::string word);
    void setItem(Item &item, Position &pos);
    Item& getItemAt(Position pos);
    void removeItems(Position pos);
    void updateMovableItems();
    std::vector<Item>& getMovables();
    Type nextPosType(Position pos, Direction dir);
    Status nextPosStatus(Position pos, Direction dir);
    std::vector<Item>& getIsItems();
    void updateItemsStatus();
    Status translateTextStatus(Type type);
    Type translateTextType(Type type);
    void findIsItems();
    bool isText(int x, int y);
    bool isInside(Position position);
    bool isEmpty(Position pos);
    bool isPushable(Position pos);
    bool isKiller(Position pos);
    bool isSink(Position pos);

   // void printBoard();
};

#endif // BOARD_H
