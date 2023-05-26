#ifndef QCONTROLLER_H
#define QCONTROLLER_H
#include "gui.h"
class QController : public QWidget {
    Q_OBJECT
    Game _game;
    Gui * _view;

private slots:
    /**
     * @brief retrieveLevel slots when clicked on the button.
     */
    void play();

public:
    QController(Game game, Gui *view);
//    void play();
    void startGame();

};

#endif // QCONTROLLER_H
