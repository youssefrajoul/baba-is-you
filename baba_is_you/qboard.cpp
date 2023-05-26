#include "qboard.h"
#include "Qitem.h"

QBoard::QBoard(Game &game) :_game(game){
}

void QBoard::updateBoard(){
    this->setContentsMargins(0,0,0,0);
    this->setSpacing(0);
    for(unsigned row = 0; row < 20; row++) {
        for(unsigned column = 0; column < 20; column++) {
            Item item = _game
                    .getBoard()
                    .getArray()[row][column]
                    .getTopItem();
            QItem *qItem = new QItem(item);
            this->addWidget(qItem,row,column);
        }
    }
}
QBoard::~QBoard(){
       while (QLayoutItem* item = this->takeAt(0)) {
        QWidget* widget = item->widget();
        if (widget) {
            delete widget;
        }
        delete item;

}
}

