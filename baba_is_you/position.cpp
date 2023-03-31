#include "position.h"

Position::Position(int x,int y){
    this->x = x;
    this->y = y;
}

int Position::getX(){
    return x;
}

int Position::getY(){
    return y;
   }

void Position::setX(int x){
    this->x = x;
}

void Position::setY(int y){
    this->y = y;
}



bool Position::operator==(Position & lhs){
    if((lhs.getX() == this->x)&& (lhs.getY() == this->y)){
            return true;
        }
    return false;
}

std::ostream& operator<<(std::ostream& out, Position& obj) {
    return out << "(" << obj.getX() << ":" << obj.getY() << ")";
}

