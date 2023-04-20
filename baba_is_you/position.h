#ifndef POSITION_H
#define POSITION_H
#include "direction.h"



class Position{
    int x,y;
public:
    Position() = default;
    Position(int x,int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int Y);
    Position nextPos(Direction dir);
    bool operator==(Position & lhs);
    friend std::ostream& operator<<(std::ostream& out, Position& obj);
};




#endif // POSITION_H
