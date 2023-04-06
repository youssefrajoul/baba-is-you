#ifndef SQUARE_H
#define SQUARE_H
#include <vector>
#include "item.h"

class Square{
    std::vector<Item> _items;
public:
    Square()=default;
    Square(Item &item);
    Item getTopItem();
    std::vector<Item> getAllItems();
    void setItem(Item &item);
    void cleanSquare();
};

#endif // SQUARE_H
