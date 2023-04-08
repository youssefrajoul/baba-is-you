#include <iostream>
#include <vector>
#include <string>

#include "board.h"
#include "square.h"
#include "item.h"

Board::Board(int rows, int cols) {
    this->_rows = rows;
    this->_cols = cols;
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

std::array<std::array<Square, 20>, 20> &Board::getBoard(){
    return this->_array;
}

void Board::fillBoard(std::vector<std::vector<std::string>> items){
    for (unsigned i = 1; i < items.size(); i++) {
        Position pos(std::stoi(items[i][2])+1, std::stoi(items[i][1])+1);
        std::pair<Type, Status> pair = getType(items[i][0]);
        Type type = pair.first;
        Status status = pair.second;
        Item item(pos, type, status);
        setItem(item, pos);
    }
}

std::pair<Type, Status> Board::getType(std::string word){
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
        type = Type::IS;
        status = Status::PUSH;
    }
    else if (word == "flag") {
        type = Type::FLAG;
        status = Status::PUSH;
    }
    else if (word == "stop") {
        type = Type::STOP;
        status = Status::PUSH;
    }
    else if (word == "baba") {
        type = Type::BABA;
        status = Status::MOVE;
    }
    else if (word == "skull") {
        type = Type::SKULL;
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
    else if (word == "water") {
        type = Type::WATER;
        status = Status::SINK;
    }
    else if (word == "text_flag") {
        type = Type::TEXT_FALG;
        status = Status::PUSH;
    }
    else if (word == "win") {
        type = Type::WIN;
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
        type = Type::BEST;
        status = Status::STOP;
    }
    else if (word == "you") {
        type = Type::YOU;
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

Item Board::getItem(Position pos){
    return this->_array[pos.getX()][pos.getY()].getTopItem();
}

void Board::removeItems(Position pos){
    _array[pos.getX()][pos.getY()].cleanSquare();
}

Status Board::nextPosStatus(Position pos, Direction dir){
    Position nextPos(pos.getX(), pos.getY());// nextPos algorithm TODO
    return this->_array[nextPos.getX()][nextPos.getY()].getTopItem().getStatus();
}

Type Board::nextPosType(Position pos, Direction dir){
    Position nextPos(pos.getX(), pos.getY());// nextPos algorithm TODO
    return Type::EMPTY;
}

void Board::printBoard(){
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            std::cout << " " << static_cast<char>(_array[i][j].getTopItem().getType());
        }
        std::cout << std::endl;
    }
}
