#ifndef TYPESTATUS_H
#define TYPESTATUS_H

#include "type.h"
#include "status.h"

namespace TypeStatus {

Status translateTextStatus(Type type){
    switch (type) {
    case Type::TEXT_PUSH:
        return Status::PUSH;
        break;
    case Type::TEXT_STOP:
        return Status::STOP;
        break;
    case Type::TEXT_YOU:
        return Status::MOVE;
        break;
    case Type::TEXT_WIN:
        return Status::WIN;
        break;
    case Type::TEXT_SINK:
        return Status::SINK;
        break;
    case Type::TEXT_KILL:
        return Status::KILL;
        break;
    default:
        return Status::NOTHING;
        break;
    }
}

Type translateTextType(Type type){
    switch (type) {
    case Type::TEXT_WALL:
        return Type::WALL;
        break;
    case Type::TEXT_ROCK:
        return Type::ROCK;
        break;
    case Type::TEXT_FLAG:
        return Type::FLAG;
        break;
    case Type::TEXT_BABA:
        return Type::BABA;
        break;
    case Type::TEXT_WATER:
        return Type::WATER;
        break;
    default:
        return Type::EMPTY;
        break;
    }
}

bool isTypeText(Type type){
    switch (type) {
    case Type::TEXT_BABA:
        return true;
        break;
    case Type::TEXT_WALL:
        return true;
        break;
    case Type::TEXT_WATER:
        return true;
        break;
    case Type::TEXT_FLAG:
        return true;
        break;
    case Type::TEXT_ROCK:
        return true;
        break;
    default:
        return false;
        break;
    }
    return false;
}

bool isStatusText(Type type){
    switch (type) {
    case Type::TEXT_YOU:
        return true;
        break;
    case Type::TEXT_STOP:
        return true;
        break;
    case Type::TEXT_SINK:
        return true;
        break;
    case Type::TEXT_WIN:
        return true;
        break;
    case Type::TEXT_PUSH:
        return true;
        break;
    default:
        return false;
        break;
    }
    return false;
}

bool isTextIs(Type type) {
    return type == Type::TEXT_IS;
}

}


#endif // TYPESTATUS_H
