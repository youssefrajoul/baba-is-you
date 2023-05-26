#ifndef QBOARD_H
#define QBOARD_H
#include <QWidget>
#include <QGridLayout>
#include "game.h"

/**
 * @brief The QBoard class represent the Graphical board
 */
class QBoard : public QGridLayout{
    Q_OBJECT
    /**
     * @brief _game the mode
     */
    Game &_game;
    //QGridLayout * _board;


public:
    /**
     * @brief QBoard constructer
     * @param game
     */
    explicit QBoard(Game &game);
    /**
     * @brief updateBoard to match the new board
     */
    void updateBoard();

    ~QBoard();
};

#endif // QBOARD_H
