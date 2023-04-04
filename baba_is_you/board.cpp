#include <iostream>
#include <vector>

#include "Board.h"
#include "item.h"

Board::Board(int rows, int cols) {
    this->_rows = rows;
    this->_cols = cols;

    // Allocate memory for the 2D array of squares
    board = new Square**[rows];
    for (int i = 0; i < _rows; i++) {
        board[i] = new Square*[_cols];
        for (int j = 0; j < _cols; j++) {
            board[i][j] = nullptr;
        }
    }
}

Board::~Board() {
    // Deallocate memory for the 2D array of object pointers
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            delete board[i][j];
        }
        delete[] board[i];
    }
    delete[] board;
}

void Board::fillBoard(std::vector<std::vector<std::string>> items){
    std::cout << "fillBoard Method" << std::endl;
    for (unsigned i = 1; i < items.size(); i++) {
        Position pos(std::stoi(items[i][1]), std::stoi(items[i][2]));
        Type type = Type::WALL;
        Item item(pos, type, Status::NOTHING);
        setItem(item, pos);
    }
    std::cout << "end fillBoard Method" << std::endl;
}

void Board::setItem(Item item, Position pos){
    this->board[pos.getX()][pos.getY()]->setItem(item);
}

Item Board::getItem(Position pos){
    return this->board[pos.getX()][pos.getY()]->getTopItem();
}

void Board::removeItem(Position pos){
    board[pos.getX()][pos.getY()] = nullptr;
}

//need of Status class
Status Board::nextPosStatus(Position pos, Direction dir){
    Position nextPos(pos.getX(), pos.getY());// nextPos algorithm TODO
    return this->board[nextPos.getX()][nextPos.getY()]->getTopItem().getStatus();
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
            std::cout << "0";
//            board[i][j];
        }
        std::cout << std::endl;
    }
}
