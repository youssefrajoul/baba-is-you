#ifndef ITEM_H
#define ITEM_H
#include "position.h"
#include "MaterielType.cpp"
#include "type.h"
#include "status.h"
#include "direction.h"


class Item{
    Position _position;
    Type _type;
    Status _status;

public:
    Item(Position pos, Type type, Status status);
    Position getPosition();
    void setPosition(Direction dir);
    Type getType();
    void setType(Type type);
    Status getStatus();
    void setStatus(Status status);
    friend std::ostream& operator<<(std::ostream& out, Item obj);

};

#endif // ITEM_H