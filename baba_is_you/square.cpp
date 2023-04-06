#include "square.h"

Square::Square(Item &item){
    std::cout << "test2" << std::endl;
    this->_items.insert(_items.begin(), item);
    std::cout << "test2" << std::endl;
}

Item Square::getTopItem(){
    std::cout << this->_items.size();
    return this->_items.back();
}

std::vector<Item> Square::getAllItems(){
    return this->_items;
}

void Square::setItem(Item &item){
    std::cout << this->_items.size() << std::endl;
    this->_items.push_back(item);
    std::cout << this->_items.size() << std::endl;
}

void Square::cleanSquare(){
//    _items.erase(_items.begin());
}
