#ifndef SQUARE_H
#define SQUARE_H
#include <list>
#include "item.h"

class Square{
    std::list<Item> _items;
public:
    Square() = default;
    Square(Item &item);
    Item& getTopItem();
    std::list<Item>& getAllItems();
    void addItem(Item &item);
    void cleanSquare();
    void removeTopItem();
};

#endif // SQUARE_H
