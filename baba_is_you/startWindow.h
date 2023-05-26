#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFontDatabase>
//#include "view/gui.h"
class Gui;
class Game;


/**
 * @brief The QStartWindow class represents the class QStartWindow.
 */
class QStartWindow : public QWidget {
    Q_OBJECT


public:
    /**
     * @brief QStartWindow constructor of QStartWindow.
     * @param parent
     */
    explicit QStartWindow(Gui * parent);
    /**
     * @brief getLevel getter of the level.
     * @return the level of the game
     */
    QString getLevel();
    ~QStartWindow() = default;

    QPushButton * get_start();

    Gui * getParent();

signals:
    void startClicked();
private slots:
    /**
     * @brief retrieveLevel slots when clicked on the button.
     */
    void start();
    void startLast();
private:
    /**
         * @brief logo_ the logo.
         */
    QLabel * _logo;
    /**
     * @brief start_ the button.
     */
    QPushButton * _start;
    QPushButton * _last;
    Gui * _parent;

};

#endif // STARTWINDOW_H
