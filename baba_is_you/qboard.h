#ifndef QBOARD_H
#define QBOARD_H
#include <QWidget>
#include <QGridLayout>
#include "game.h"
class QBoard : public QGridLayout{
    Q_OBJECT

    Game &_game;
    //QGridLayout * _board;


public:
    explicit QBoard(Game &game);
    void updateBoard();
    QGridLayout * getGrid();
    ~QBoard();
};

#endif // QBOARD_H
