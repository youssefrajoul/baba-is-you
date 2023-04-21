#ifndef BOARD_H
#define BOARD_H

#include "square.h"
#include "item.h"
#include "level.h"

#include <vector>
#include <array>
#include <map>

/**
 * @brief The Board class, this class
 * reprersent the board of the game.
 *
 */
class Board{
    int _rows;
    int _cols;
    bool _win;
    Level _level;
    std::array<std::array<Square, 20>, 20> _array;
    /**
     * @brief _itemsStatus, map  of stats and types.
     */
    std::map<Type, Status> _itemsStatus;
    /**
     * @brief _textTypeItems, to do.
    */
    std::vector<Item> _textTypeItems;
    /**
     * @brief _movableItems.
     */
    std::vector<Item> _movableItems;
public:
    //    these methods need to be in order cause too much (new Class?)
    Board(Level& level);
    Board() = default;
    std::array<std::array<Square, 20>, 20>& getArray();
    /**
     * @brief fillBoard,this function fill the board
     * with right item at the right position.
     * @param items, the level as a text.
     */
    void fillBoard(std::vector<std::vector<string> > items);
    //to do documentation
    void setBorders(Position pos);
    void setItem(Item &item, Position &pos);
    Item& getItemAt(Position pos);
    /**
     * @brief removeItems, to remove the
     * item at the given position.
     * @param pos, the position of the item
     * to remove.
     */
    void removeItems(Position pos);
    /**
     * @brief updateMovableItems, to update
     * the vectore of movavle items.
     */
    void updateMovableItems();
    // to do documentation
    std::vector<Item>& getMovables();
    /**
     * @brief nextPosType, this function return
     * the type of the item at the next position.
     * @param pos the actuel position
     * @param dir the direction
     * @return the type of the item;
     */
    Type nextPosType(Position pos, Direction dir);
    /**
     * @brief nextPosStatus, this function return
     * the state of the item at the next position.
     * @param pos the actuel position
     * @param dir the direction
     * @return the status of the item
     */
    Status nextPosStatus(Position pos, Direction dir);
    // to do documentation
    std::vector<Item>& getTextType();
    // to do documentation
    bool isTypeText(int x, int y);
    // to do documentation
    void updateType(Type type, Type newType);
    // to do documentation
    void updateRules();
    // to do documentation
    void horizontalRule(Position typePos, bool &ruleExists);
    // to do documentation
    void verticalRule(Position typePos, bool &ruleExists);
    // to do documentation
    void updateItemsStatus();
    // to do documentation
    void findTypeTexts();
    // to do documentation
    /**
     * @brief isInside, to test if the given
     * position is inside the board.
     * @param position, the given position
     * @return true if it's inside, false if not
     */
    bool isInside(Position position);
    /**
     * @brief isWin, getter for _win membre
     * @return
     */
    bool isWin();
    /**
     * @brief setWin setter for _win member
     * @param b
     */
    void setWin(bool b);
};

#endif // BOARD_H
