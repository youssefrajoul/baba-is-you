#ifndef SQUARE_H
#define SQUARE_H
#include <vector>
#include "item.h"

class Square{
    std::vector<Item> items;
public:
    Square()=default;
    Square(Item item);
    Item getTopItem();
    std::vector<Item> getAllItems();
    void setItem(Item item);
};

#endif // SQUARE_H
