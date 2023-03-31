#ifndef SQUARE_H
#define SQUARE_H
#include <list>
#include "item.h"

class Square{
    std::list<Item> items;
public:
    Square()=default;
    Square(Item item);
    Item getTopItem();
    std::list<Item> getAllItems();
    void setItem(Item item);
};

#endif // SQUARE_H
