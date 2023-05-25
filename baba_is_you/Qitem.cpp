#include "Qitem.h"

QItem::QItem(Item &item) : _item(item){
    QString url = "./resource/img/images";
    Type type = _item.getType();
    switch(type) {
    case Type::BABA :
        url += "/baba.png";
        break;
    case Type::EMPTY :
        url += "/earth.png";
        break;
    case Type::END :
        url += "/cadre.png";
        break;
    case Type::FLAG :
        url += "/flag.png";
        break;
    case Type::GRASS:
        url += "/gras.png";
        break;
    case Type::LAVA :
        url += "/lava.png";
        break;
    case Type::METAL :
        url += "/metal.png";
        break;
    case Type::ROCK :
        url += "/rock.png";
        break;
    case Type::TEXT_SINK :
        url += "/sink.png";
        break;
    case Type::WALL :
        url += "/wall.png";
        break;
    case Type::WATER :
        url += "/water.png";
        break;
    case Type::TEXT_BABA :
        url += "/tbaba.png";
        break;
    case Type::TEXT_IS :
        url += "/is.png";
        break;
    case Type::TEXT_FLAG :
        url += "/tflag.png";
        break;
    case Type::TEXT_LAVA :
        url += "/tbaba.png";
        break;
    case Type::TEXT_ROCK :
        url += "/trock.png";
        break;
    case Type::TEXT_WALL :
        url += "/twall.png";
        break;
    case Type::TEXT_STOP :
        url += "/stop.png";
        break;
    case Type::TEXT_PUSH :
        url += "/push.png";
        break;
    case Type::TEXT_WIN :
        url += "/win.png";
        break;
    case Type::TEXT_KILL :
        url += "/kill.png";
        break;
    case Type::TEXT_YOU :
        url += "/you.png";
        break;
    case Type::TEXT_WATER :
        url += "/tbaba.png";
        break;
    case Type::TEXT_BEST :
        url += "/tbaba.png";
        break;
    case Type::TEXT_ICE :
        url += "/tbaba.png";
        break;
    case Type::TEXT_GRASS :
        url += "/tbaba.png";
        break;
    case Type::TEXT_EMPTY :
        url += "/tbaba.png";
        break;

    }
    QPixmap qp(url);


    this->setPixmap(qp.scaled(30,30));
  //  this->setScaledContents(true);
}
