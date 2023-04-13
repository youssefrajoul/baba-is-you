#include <iostream>
#include <vector>
#include <string>

#include "board.h"
#include "level.h"
#include "square.h"
#include "item.h"

Board::Board(Level& level) : _level(level){
 //   std::cout << "Board Object Creation" << std::endl;
    this->_rows = this->_level.getRows();
    this->_cols = this->_level.getCols();
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if(i == 0) {
                Position pos(i, j);
                Type type = Type::END;
                Item item(pos, type, Status::STOP);
                setItem(item, pos);
            } else if (i == 19) {
                Position pos(i, j);
                Type type = Type::END;
                Item item(pos, type, Status::STOP);
                setItem(item, pos);
            } else if (j == 0) {
                Position pos(i, j);
                Type type = Type::END;
                Item item(pos, type, Status::STOP);
                setItem(item, pos);
            } else if (j == 19) {
                Position pos(i, j);
                Type type = Type::END;
                Item item(pos, type, Status::STOP);
                setItem(item, pos);
            } else {
                Position pos(i, j);
                Type type = Type::EMPTY;
                Item item(pos, type, Status::NOTHING);
                setItem(item, pos);
            }
        }
    }
}

std::array<std::array<Square, 20>, 20>& Board::getArray(){
    return this->_array;
}

void Board::fillBoard(std::vector<std::vector<std::string>> items){
    for (unsigned i = 1; i < items.size(); i++) {
        Position pos(std::stoi(items[i][2])+1, std::stoi(items[i][1])+1);
        std::pair<Type, Status> pair = getTypeStatus(items[i][0]);
        Type type = pair.first;
        Status status = pair.second;
        Item item(pos, type, status);
        setItem(item, pos);
    }
}

std::pair<Type, Status> Board::getTypeStatus(std::string word){
    Type type;
    Status status;
    if (word == "grass") {
        type = Type::GRASS;
        status = Status::STOP;
    }
    else if (word == "wall") {
        type = Type::WALL;
        status = Status::STOP;
    }
    else if (word == "metal") {
        type = Type::METAL;
        status = Status::NOTHING;
    }
    else if (word == "is") {
        type = Type::TEXT_IS;
        status = Status::PUSH;
    }
    else if (word == "flag") {
        type = Type::FLAG;
        status = Status::PUSH;
    }
    else if (word == "stop") {
        type = Type::TEXT_STOP;
        status = Status::STOP;
    }
    else if (word == "baba") {
        type = Type::BABA;
        status = Status::MOVE;
    }
    else if (word == "skull") {
        type = Type::SKULL;
        status = Status::KILL;
    }
    else if (word == "lava") {
        type = Type::LAVA;
        status = Status::KILL;
    }
    else if (word == "ice") {
        type = Type::ICE;
        status = Status::STOP;
    }
    else if (word == "rock") {
        type = Type::ROCK;
        status = Status::PUSH;
    }
    else if (word == "text_rock") {
        type = Type::TEXT_ROCK;
        status = Status::PUSH;
    }
    else if (word == "water") {
        type = Type::WATER;
        status = Status::SINK;
    }
    else if (word == "text_flag") {
        type = Type::TEXT_FLAG;
        status = Status::PUSH;
    }
    else if (word == "win") {
        type = Type::TEXT_WIN;
        status = Status::WIN;
    }
    else if (word == "push") {
        type = Type::TEXT_PUSH;
        status = Status::PUSH;
    }
    else if (word == "text_baba") {
        type = Type::TEXT_BABA;
        status = Status::PUSH;
    }
    else if (word == "text_wall") {
        type = Type::TEXT_WALL;
        status = Status::PUSH;
    }
    else if (word == "text_best") {
        type = Type::TEXT_BEST;
        status = Status::PUSH;
    }
    else if (word == "you") {
        type = Type::TEXT_YOU;
        status = Status::PUSH;
    }
    else if (word == "text_water") {
        type = Type::TEXT_WATER;
        status = Status::PUSH;
    }
    else if (word == "sink") {
        type = Type::TEXT_SINK;
        status = Status::PUSH;
    }else {
        type = Type::EMPTY;
        status = Status::NOTHING;
    }
    return std::make_pair(type, status);
}

void Board::setItem(Item &item, Position &pos){
    this->_array[pos.getX()][pos.getY()].addItem(item);
}

Item &Board::getItemAt(Position pos){
    return this->_array[pos.getX()][pos.getY()].getTopItem();
}

void Board::removeItems(Position pos){
    _array[pos.getX()][pos.getY()].cleanSquare();
}

Status Board::nextPosStatus(Position pos, Direction dir){
    switch(dir){
    case Direction::UP :
        pos.setX(pos.getX()-1);
        return this->getItemAt(pos).getStatus();
        break;
    case Direction::LEFT :
        pos.setY(pos.getY()-1);
        return this->getItemAt(pos).getStatus();
        break;
    case Direction::RIGHT :
        pos.setY(pos.getY()+1);
        return this->getItemAt(pos).getStatus();
        break;
    case Direction::DOWN :
        pos.setX(pos.getX()-1);
        return this->getItemAt(pos).getStatus();
        break;
    }
    return this->getItemAt(pos).getStatus();
}

Type Board::nextPosType(Position pos, Direction dir){

    switch(dir){
    case Direction::UP :
        pos.setX(pos.getX()-1);
        return this->getItemAt(pos).getType();
        break;
    case Direction::LEFT :
        pos.setY(pos.getY()-1);
        return this->getItemAt(pos).getType();
        break;
    case Direction::RIGHT :
        pos.setY(pos.getY()+1);
        return this->getItemAt(pos).getType();
        break;
    case Direction::DOWN :
        pos.setX(pos.getX()-1);
        return this->getItemAt(pos).getType();
        break;
    }
    return this->getItemAt(pos).getType();
}

bool Board::isText(int x, int y){
    Type type = _array[x][y].getTopItem().getType();
    //    if(type == Type::TEXT_BABA || type == Type::TEXT_BABA || )
    switch (type) {
    case Type::TEXT_BABA:
        return true;
        break;
    case Type::TEXT_YOU:
        return true;
        break;
    case Type::TEXT_WALL:
        return true;
        break;
    case Type::TEXT_STOP:
        return true;
        break;
    case Type::TEXT_WATER:
        return true;
        break;
    case Type::TEXT_FLAG:
        return true;
        break;
    case Type::TEXT_SINK:
        return true;
        break;
    case Type::TEXT_WIN:
        return true;
        break;
    case Type::TEXT_ROCK:
        return true;
        break;
    case Type::TEXT_PUSH:
        return true;
        break;
    default:
        return false;
        break;
    }
    return false;
}

Status Board::translateTextStatus(Type type){
    switch (type) {
    case Type::TEXT_PUSH:
        return Status::PUSH;
        break;
    case Type::TEXT_STOP:
        return Status::STOP;
        break;
    case Type::TEXT_YOU:
        return Status::MOVE;
        break;
    case Type::TEXT_WIN:
        return Status::WIN;
        break;
    case Type::TEXT_SINK:
        return Status::SINK;
        break;
    case Type::TEXT_KILL:
        return Status::KILL;
        break;
    default:
        return Status::NOTHING;
        break;
    }
}
Type Board::translateTextType(Type type){
    switch (type) {
    case Type::TEXT_WALL:
        return Type::WALL;
        break;
    case Type::TEXT_ROCK:
        return Type::ROCK;
        break;
    case Type::TEXT_FLAG:
        return Type::FLAG;
        break;
    case Type::TEXT_BABA:
        return Type::BABA;
        break;
    default:
        return Type::EMPTY;
        break;
    }
}

void Board::updateItemsStatus(){
    _itemsStatus.clear();
    Type typeH;
    Status statusH;
    Type typeV;
    Status statusV;
    std::cout << "is items size " << _isItems.size() << std::endl;
    for (unsigned i = 0; i < _isItems.size(); i++) {
        Position pos = _isItems[i].getPosition();
        if(isText(pos.getX(), pos.getY()-1) && isText(pos.getX(), pos.getY()+1)) {
            // Left of IS
            typeH = translateTextType(_array[pos.getX()][pos.getY()-1].getTopItem().getType());
            // Right of IS
            statusH = translateTextStatus(_array[pos.getX()][pos.getY()+1].getTopItem().getType());
            _itemsStatus[statusH] = typeH;
        }
        if(isText(pos.getX()-1, pos.getY()) && isText(pos.getX()+1, pos.getY())){
            // Above IS
            typeV = translateTextType(_array[pos.getX()-1][pos.getY()].getTopItem().getType());
            // Bottom of IS
            statusV = translateTextStatus(_array[pos.getX()+1][pos.getY()].getTopItem().getType());
            _itemsStatus[statusV] = typeV;
        }
    }
}


void Board::updateMovableItems(){
    // TODO call methods here
    findIsItems();
    updateItemsStatus();
    _movableItems.clear();
    Type type = _itemsStatus[Status::MOVE];

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if(_array[i][j].getTopItem().getType() == type){
                _movableItems.push_back(_array[i][j].getTopItem());
                std::cout << "type: " << static_cast<char>(_array[i][j].getTopItem().getType()) << std::endl;
                std::cout << "X: " << _array[i][j].getTopItem().getPosition().getX() << "i: " << i << std::endl;
                std::cout << "Y: " << _array[i][j].getTopItem().getPosition().getY() << "j: " << j << std::endl;

            }
        }
    }
    std::cout << "movableItems size " << _movableItems.size() << std::endl;
}

void Board::findIsItems(){
    getIsItems().clear();
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if(_array[i][j].getTopItem().getType() == Type::TEXT_IS){
                getIsItems().push_back(_array[i][j].getTopItem());
            }
        }
    }
}

std::vector<Item>& Board::getIsItems(){
    return this->_isItems;
}
//////////////////////////////////////////

std::vector<Item> &Board::getMovables(){
    return this->_movableItems;
}

bool Board::isInside(Position position) {
    if(position.getX() < 0 || position.getX() > this->_rows) {
        return false;
    } else if(position.getY() < 0 || position.getY() > this->_cols) {
        return false;
    }
    return true;
}

bool Board::isEmpty(Position pos){
    return (this->getItemAt(pos).getType()== Type::EMPTY || this->getItemAt(pos).getType()== Type::METAL);
}
bool Board::isPushable(Position pos){

    return (this->getItemAt(pos).getStatus()== Status::PUSH);
}


