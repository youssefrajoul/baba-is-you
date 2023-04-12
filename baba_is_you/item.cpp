#include "item.h"

Item::Item(Position pos, Type type, Status status){
    this->_position = pos;
    this->_type = type;
    this->_status = status;
}

Position Item::getPosition(){
    return this->_position;
}

void Item::setPosition(Position pos){
    this->_position.setX(pos.getX());
    this->_position.setY(pos.getY());


}

Type Item::getType(){
    return this->_type;
}

void Item::setType(Type type) {
    this->_type = type;
}

Status Item::getStatus(){
    return this->_status;
}

void Item::setStatus(Status status){
    this->_status = status;
}

std::ostream& operator<<(std::ostream& out, Item obj){
    return out << "à faire plus tard";

}
