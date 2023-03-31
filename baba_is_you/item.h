#ifndef ITEM_H
#define ITEM_H
#include "position.h"
#include "MaterielType.cpp"
#include "direction.h"


class Item{
    Position position;
    Materiel_Type type;

public:
    Item(Position pos, Materiel_Type type);
    Position getPosition();
    void setPosition(Direction dir);
    std::string getStatus();
    friend std::ostream& operator<<(std::ostream& out, Item obj);

};

#endif // ITEM_H
