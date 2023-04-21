#include "square.h"

Square::Square(Item &item){
    this->_items.push_back(item);
}

Item& Square::getTopItem(){
    return this->_items.back();
}

std::vector<Item> &Square::getAllItems(){
    return this->_items;
}

void Square::addItem(Item &item){
    this->_items.push_back(item);
}

void Square::cleanSquare(){
    _items.erase(_items.begin());
}

void Square::removeTopItem(){
    this->_items.pop_back();
}
