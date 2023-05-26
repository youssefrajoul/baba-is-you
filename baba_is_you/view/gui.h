#ifndef GUI_H
#define GUI_H
#include "game.h"
#include <QWidget>
#include "startWindow.h"
#include "qboard.h"
#include <QKeyEvent>
/**
 * @brief The Gui class represent the graphical interface
 * of the game
 */
class Gui : public QWidget, public Observer{
    Game &_game;
    /**
     * @brief _startWindow tha reception window
     */
    QStartWindow * _startWindow;
    /**
     * @brief _window the main window
     */
    QHBoxLayout * _window;
    /**
     * @brief _qboard the graphical board
     */
    QBoard * _qboard;

public:
    explicit Gui(Game &game, QWidget * parent = nullptr);
    /**
     * @brief displayStartWindow to display the reception window
     */
    void displayStartWindow();
    /**
     * @brief displayBoards display the board
     */
    void displayBoards();
    /**
     * @brief update observer update methode
     * @param observable
     */
    void update(Observable * observable) override;
    /**
     * @brief updateBoard update graphical board
     */
    void updateBoard();
    /**
     * @brief displayLastBoards display saved board
     */
    void displayLastBoards();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // GUI_H

