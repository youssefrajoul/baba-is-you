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
    bool operator==(Item & lhs);
    friend std::ostream& operator<<(std::ostream& out, Item obj);

};

#endif // ITEM_H
