#include "position.h"

Position::Position(int x,int y) : x{x}, y{y}{
//    this->x = x;
//    this->y = y;
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

Position Position::nextPos(Direction dir){
    Position nextPos;
    switch(dir){
    case Direction::UP :
        nextPos = Position(this->getX()-1,this->getY());
        break;
    case Direction::LEFT :
        nextPos = Position(this->getX(),this->getY()-1);
        break;
    case Direction::RIGHT :
        nextPos = Position(this->getX(),this->getY()+1);
        break;
    case Direction::DOWN :
        nextPos = Position(this->getX()+1,this->getY());
        break;
    }
    return nextPos;
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
