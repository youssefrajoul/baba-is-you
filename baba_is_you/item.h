#ifndef ITEM_H
#define ITEM_H
#include "position.h"
#include "type.h"
#include "status.h"

/**
 * @brief The Item class, represent an item
 */
class Item{
    Position _position;
    Type _type;
    Status _status;

public:
    Item() = default;
    Item(Position& pos, Type type, Status status);
    Position& getPosition();
    void setPosition(Position& pos);
    Type getType();
    void setType(Type type);
    Status getStatus();
    void setStatus(Status status);
    /**
     * @brief isEmpty, to test if the given
     * position is an empty square.
     * @param pos the given position
     * @return true if it's empty, false if not
     */
    bool isEmpty();
    /**
     * @brief isPushable,to test if the given
     * position has a pushable item.
     * @param pos, given position
     * @return true if it's pushable, false if not
     */
    bool isPushable();
    /**
     * @brief isKiller, to test if the given
     * position has a killer item.
     * @param pos, the given position
     * @return true if it's killer, false if not
     */
    bool isKiller();
    /**
     * @brief isSink, to test if the given
     * position has a sink item.
     * @param pos given position
     * @return true if it's sink, false if not
     */
    bool isSink();
    bool isWinable();
    bool isStop();
    bool isMovable();
    bool operator==(Item & lhs);
    friend std::ostream& operator<<(std::ostream& out, Item obj);

};

#endif // ITEM_H
