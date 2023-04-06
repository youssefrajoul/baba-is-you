#include <iostream>
#include <vector>

#include "board.h"
#include "square.h"
#include "item.h"

Board::Board(int rows, int cols) {
    this->_rows = rows;
    this->_cols = cols;
    std::cout << "board creation" << std::endl;
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            Position pos(i, j);
            Type type = Type::EMPTY;
            Item item(pos, type, Status::NOTHING);
            Square square(item);
            this->_array[pos.getX()][pos.getY()] = square;
        }
    }
}

void Board::fillBoard(std::vector<std::vector<std::string>> items){
    std::cout << "fill board" << std::endl;
    for (unsigned i = 1; i < items.size(); i++) {
        Position pos(std::stoi(items[i][1]), std::stoi(items[i][2]));
        Type type = Type::SKULL;
        Item item(pos, type, Status::KILL);
        setItem(item, pos);
    }
}

void Board::setItem(Item &item, Position &pos){
    this->_array[pos.getX()][pos.getY()]->setItem(item);
}

Item Board::getItem(Position pos){
    return this->_array[pos.getX()][pos.getY()]->getTopItem();
}

void Board::removeItems(Position pos){
    _array[pos.getX()][pos.getY()]->cleanSquare();
}

Status Board::nextPosStatus(Position pos, Direction dir){
    Position nextPos(pos.getX(), pos.getY());// nextPos algorithm TODO
    return this->_array[nextPos.getX()][nextPos.getY()]->getTopItem().getStatus();
}

Type Board::nextPosType(Position pos, Direction dir){
    Position nextPos(pos.getX(), pos.getY());// nextPos algorithm TODO
    //    return this->board[nextPos.getX()][nextPos.getY()]->getTopItem().getType();
    return Type::EMPTY;
}

void Board::printBoard(){
    std::cout << "print Board Method" << std::endl;
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            std::cout << " " << static_cast<char>(_array[i][j]->getAllItems()[0].getType());
        }
        std::cout << std::endl;
    }
}
