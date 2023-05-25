#ifndef QITEM_H
#define QITEM_H

#include "game.h"
#include <QLabel>

class QItem : public QLabel{
    Q_OBJECT
    Item &_item;

public:
    QItem(Item &item);
    ~QItem()=default;


};

#endif // QITEM_H
