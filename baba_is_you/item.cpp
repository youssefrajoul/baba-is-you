#include "item.h"

Item::Item(Position pos, Type type, Status status){
    this->_position = pos;
    this->_type = type;
    this->_status = status;
}

Position Item::getPosition(){
    return this->_position;
}

void Item::setPosition(Direction dir){
    //à faire plus tard
}

Type getType(){
    //    Type::BABA to be removed later
    return Type::BABA;
}

void Item::setType(Type type) {
    this->_type = type;
}

Status Item::getStatus(){
    //    Status::KILL to be removed later
    return Status::KILL;
}

void Item::setStatus(Status status){
    this->_status = status;
}

std::ostream& operator<<(std::ostream& out, Item obj){
    return out << "à faire plus tard";

}