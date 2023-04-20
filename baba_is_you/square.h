#ifndef SQUARE_H
#define SQUARE_H
#include <list>
#include "item.h"
/**
 * @brief The Square class, represent a
 * square on the board of the game.
 * it's a list of item.
 */
class Square{
    std::list<Item> _items;
public:
    Square() = default;
    Square(Item &item);
    /**
     * @brief getTopItem, this function
     * return the item on the top of the square.
     * @return the top item
     */
    Item& getTopItem();
    /**
     * @brief getAllItems,this function
     * return all the items in square.
     * @return a list of Item;
     */
    std::list<Item>& getAllItems();
    /**
     * @brief addItem, to add a new item
     *  in the square
     * @param item, the item to add
     */
    void addItem(Item &item);
    /**
     * @brief cleanSquare, to remove all
     * the items from the square
     */
    void cleanSquare();
    /**
     * @brief removeTopItem, to remove
     * the top item from the square
     */
    void removeTopItem();
};

#endif // SQUARE_H
