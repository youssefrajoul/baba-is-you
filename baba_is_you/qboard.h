#ifndef QBOARD_H
#define QBOARD_H
#include <QWidget>
#include <QGridLayout>
#include "Qitem.h"
#include "game.h"
class QBoard : public QWidget{
   Q_OBJECT

    Game &_game;
    QGridLayout * _board;


public:
   explicit QBoard(Game &game,QWidget *parent = nullptr);
    void updateBoard();
    QGridLayout * getGrid();

};

#endif // QBOARD_H
