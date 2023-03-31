#include "square.h"

Square::Square(Item item){
    this->items.push_back(item);
}

Item Square::getTopItem(){
    return this->items.back();
}

std::list<Item> Square::getAllItems(){
    return this->items;
}
void Square::setItem(Item item){
    this->items.push_back(item);
}




