#include <QApplication>
#include "game.h"
#include "view/qcontroller.h"
#include "view/gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game game;
    Gui *view = new Gui(game);
    game.attach(view);
    QController controller(game, view);
    controller.startGame();

    return a.exec();
}
