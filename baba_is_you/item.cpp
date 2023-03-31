#include "item.h"

Item::Item(Position pos, Materiel_Type type){
    this->position = pos;
    this->type = type;
}

Position Item::getPosition(){
return this->position;
}

void Item::setPosition(Direction dir){

    //à faire plus tard
}

std::string Item::getStatus(){

}

 std::ostream& operator<<(std::ostream& out, Item obj){
     return out << "à faire plus tard";

}
