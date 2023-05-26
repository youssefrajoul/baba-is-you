#include <QApplication>
#include "game.h"
#include "view/qcontroller.h"
#include "view/gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ////  Position p(1,2);
    ////  Type t = Type::BABA;
    ////  Status s = Status::KILL;

    ////  Item i(p,t,s);
    ////  std::cout<< i<<std::endl;
    ////  QItem qi(i);
    //  QPixmap qp("./resource/img/images/rock.png");
    //  QLabel *ql = new QLabel();
    //  ql->setPixmap(qp);
    //  QWidget *qw = new QWidget;
    ////  //ql->show();
    ////  //qi.show();


    //    Game g;
    //    //Game *ptrG = &g;
    //    g.renderBoard();
    //    QBoard b(g);
    //    b.updateBoard();
    //    //b.show();
    //    qw->setLayout(b.getGrid());
    //    qw->show();

    //    QGridLayout *qg = new QGridLayout();
    //    qw->setLayout(qg);
    //    qg->addWidget(ql,3,3);
    //    qw->show();

    Game game;
    Gui *view = new Gui(game);
    QController controller{game,view};
    controller.startGame();
    //  view->displayStartWindow();

    return a.exec();
}
