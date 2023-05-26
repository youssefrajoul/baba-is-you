#include "qboard.h"

QBoard::QBoard(Game &game,QWidget * parent):QWidget{parent}, _game(game){
    _board = new QGridLayout();
}

void QBoard::updateBoard(){
    _board->setContentsMargins(0,0,0,0);
    _board->setSpacing(0);
   // _board->
//    _game.renderBoard();
    for(unsigned row = 0; row < 20; row++) {
        for(unsigned column = 0; column < 20; column++) {
            Item item = _game
                    .getBoard()
                    .getArray()[row][column]
                    .getTopItem();
            QItem *qItem = new QItem(item);
            _board->addWidget(qItem,row,column);
        }
    }
}

QGridLayout * QBoard::getGrid(){
    return this->_board;
}
