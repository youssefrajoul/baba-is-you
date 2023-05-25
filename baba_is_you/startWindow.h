#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFontDatabase>
//#include "view/gui.h"


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
    explicit QStartWindow(QWidget * parent = nullptr);
    /**
     * @brief getLevel getter of the level.
     * @return the level of the game
     */
    QString getLevel();
    ~QStartWindow() = default;

    QPushButton * get_start();

//signals:
//    /**
//     * @brief started gives the level chosen by the player.
//     * @param value the level
//     */
//    void started(QString value);

private slots:
    /**
     * @brief retrieveLevel slots when clicked on the button.
     */
    void start();

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


};

#endif // STARTWINDOW_H
