#include "item.h"

Item::Item(Position& pos, Type type, Status status){
    this->_position = pos;
    this->_type = type;
    this->_status = status;
}

Position& Item::getPosition(){
    return this->_position;
}

void Item::setPosition(Position& pos){
    this->_position = pos;
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

bool Item::isEmpty(){
    //TODO must check this method/algorithm
    return (getType()== Type::EMPTY
            || getType()== Type::METAL
            || getStatus() == Status::NOTHING);
}

bool Item::isPushable(){
    return getStatus()== Status::PUSH;
}

bool Item::isKiller(){
    return getStatus()== Status::KILL;
}

bool Item::isSink(){
    return getStatus()== Status::SINK;
}
bool Item::isWinable(){
    return getStatus()== Status::WIN;
}

bool Item::isStop(){
    return getStatus()== Status::STOP;
}

std::ostream& operator<<(std::ostream& out, Item obj){
    return out << "à faire plus tard";

}

bool Item::operator==(Item & lhs){
    if((lhs.getPosition() == this->_position)
            && (lhs.getStatus() == this->_status)
            && lhs.getType() == this->_type){
        return true;
    }
    return false;
}
