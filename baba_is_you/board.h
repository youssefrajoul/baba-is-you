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
    /**
     * @brief setBorders, puts the borders of the board.
     * @param pos position where to put that border item.
     */
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
    /**
     * @brief getMovables, Gets the items that respects the rule type is you
     * @return return items to be moved
     */
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
//    /**
//     * @brief getTextType
//     * @return
//     */
//    std::vector<Item>& getTextType();
    // to do documentation
//    bool isTypeText(int x, int y);
    /**
     * @brief updateType, sets the type of the item
     * @param type is the old type
     * @param newType is the newest
     */
    void updateType(Type type, Type newType);
    /**
     * @brief updateRules, Updates the rules of the game (ex: wall is push)
     */
    void updateRules();
    /**
     * @brief horizontalRule, update horizontal rules (ex: wall is push)
     * @param typePos the type that will get the rule
     * @param ruleExists check if the rule was modified or not
     * if not gives the status/rule nothing to the type
     */
    void horizontalRule(Position typePos, bool &ruleExists);
    /**
     * @brief verticalRule, updates vertical rules.
     * @param typePos
     * @param ruleExists
     */
    void verticalRule(Position typePos, bool &ruleExists);
    /**
     * @brief updateItemsStatus, updates the status of each item that exists in the map
     */
    void updateItemsStatus();
    /**
     * @brief findTypeTexts, looks and saves the text items
     * like water, baba, rock
     */
    void findTypeTexts();
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
