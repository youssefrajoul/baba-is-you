#ifndef POSITION_H
#define POSITION_H
#include "direction.h"
#include <iostream>


/**
 * @brief The Position class
 * this class represent the position.
 * on the Boarde
 * where y represent the columns
 * and x represent the lines
 */
class Position{
    int x,y;
public:
    Position() = default;
    Position(int x,int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int Y);
    /**
     * @brief nextPos this function return the
     * next position on the given direction.
     * @param dir direction
     * @return a new Position
     */
    Position nextPos(Direction dir);
    bool operator==(Position & lhs);
    friend std::ostream& operator<<(std::ostream& out, Position& obj);
};




#endif // POSITION_H
