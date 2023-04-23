#include "board.h"
#include "typeStatus.h"

Board::Board(Level& level) : _level(level){
    this->_rows = 18;
    this->_cols = 18;
    this->_win = false;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if(i == 0) {
                Position pos(i, j);
                setBorders(pos);
            } else if (i == 19) {
                Position pos(i, j);
                setBorders(pos);
            } else if (j == 0) {
                Position pos(i, j);
                setBorders(pos);
            } else if (j == 19) {
                Position pos(i, j);
                setBorders(pos);
            } else {
                Position pos(i, j);
                Type type = Type::EMPTY;
                Item item(pos, type, Status::NOTHING);
                _itemsStatus[type] = Status::NOTHING;
                setItem(item, pos);
            }
        }
    }
}

void Board::setBorders(Position pos){
    Type type = Type::END;
    Item item(pos, type, Status::STOP);
    _itemsStatus[type] = Status::STOP;
    setItem(item, pos);
}

std::array<std::array<Square, 20>, 20>& Board::getArray(){
    return this->_array;
}

void Board::fillBoard(std::vector<std::vector<std::string>> items){
    for (unsigned i = 1; i < items.size(); i++) {
        Position pos(std::stoi(items[i][2])+1, std::stoi(items[i][1])+1);
        std::pair<Type, Status> pair = _level.translateFile(items[i][0]);
        Type type = pair.first;
        Status status = pair.second;
        _itemsStatus[type] = status;
        Item item(pos, type, status);
        setItem(item, pos);
    }
}

void Board::setItem(Item &item, Position &pos){
    this->_array[pos.getX()][pos.getY()].addItem(item);
}

Item &Board::getItemAt(Position pos){
    return this->_array[pos.getX()][pos.getY()].getTopItem();
}

void Board::removeItems(Position pos){
    _array[pos.getX()][pos.getY()].cleanSquare();
}

Status Board::nextPosStatus(Position pos, Direction dir){
    switch(dir){
    case Direction::UP :
        pos.setX(pos.getX()-1);
        return this->getItemAt(pos).getStatus();
        break;
    case Direction::LEFT :
        pos.setY(pos.getY()-1);
        return this->getItemAt(pos).getStatus();
        break;
    case Direction::RIGHT :
        pos.setY(pos.getY()+1);
        return this->getItemAt(pos).getStatus();
        break;
    case Direction::DOWN :
        pos.setX(pos.getX()-1);
        return this->getItemAt(pos).getStatus();
        break;
    }
    return this->getItemAt(pos).getStatus();
}

Type Board::nextPosType(Position pos, Direction dir){

    switch(dir){
    case Direction::UP :
        pos.setX(pos.getX()-1);
        return this->getItemAt(pos).getType();
        break;
    case Direction::LEFT :
        pos.setY(pos.getY()-1);
        return this->getItemAt(pos).getType();
        break;
    case Direction::RIGHT :
        pos.setY(pos.getY()+1);
        return this->getItemAt(pos).getType();
        break;
    case Direction::DOWN :
        pos.setX(pos.getX()-1);
        return this->getItemAt(pos).getType();
        break;
    }
    return this->getItemAt(pos).getType();
}

void Board::updateType(Type type, Type newType){
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j < 19; j++) {
            if(_array[i][j].getTopItem().getType() == type) {
                _array[i][j].getTopItem().setType(newType);
            }
        }
    }
}

void Board::updateRules(){
    for (unsigned i = 0; i < this->_textTypeItems.size(); i++) {
        bool ruleExists = false;
        Position typePos = this->_textTypeItems[i].getPosition();
        horizontalRule(typePos, ruleExists);
        /////////////////////////////////////////////////////////
        verticalRule(typePos, ruleExists);
    }
}

void Board::horizontalRule(Position typePos, bool &ruleExists){
    Type typeH;
    Status statusH;
    Position textIsPos(typePos.getX(), typePos.getY()+1);
    Position textStatusPos(typePos.getX(), typePos.getY()+2);
    bool isTextIsH = TypeStatus::isTextIs(getItemAt(textIsPos).getType());
    bool isStatusH = TypeStatus::isStatusText(getItemAt(textStatusPos).getType());
    bool isTypeH = TypeStatus::isTypeText(getItemAt(textStatusPos).getType());
    if(isTextIsH && isStatusH) {
        typeH = TypeStatus::translateTextType(getItemAt(typePos).getType());
        statusH = TypeStatus::translateTextStatus(getItemAt(textStatusPos).getType());
        _itemsStatus[typeH] = statusH;
        ruleExists = true;
    }else if(isTextIsH && isTypeH){
        updateType(TypeStatus::translateTextType(getItemAt(typePos).getType()), TypeStatus::translateTextType(getItemAt(textStatusPos).getType()));
    }
}

void Board::verticalRule(Position typePos, bool &ruleExists){
    Type typeV;
    Status statusV;
    Position isPosDown(typePos.getX()+1, typePos.getY());
    Position statusPosDown(typePos.getX()+2, typePos.getY());
    bool isTextIsV = TypeStatus::isTextIs(getItemAt(isPosDown).getType());
    bool isStatusV = TypeStatus::isStatusText(getItemAt(statusPosDown).getType());
    bool isTypeV = TypeStatus::isTypeText(getItemAt(statusPosDown).getType());
    if(isTextIsV && isStatusV) {
        typeV = TypeStatus::translateTextType(getItemAt(typePos).getType());
        statusV = TypeStatus::translateTextStatus(getItemAt(statusPosDown).getType());
        _itemsStatus[typeV] = statusV;
        ruleExists = true;
    }else if(isTextIsV && isTypeV){
        updateType(TypeStatus::translateTextType(getItemAt(typePos).getType()), TypeStatus::translateTextType(getItemAt(statusPosDown).getType()));
    }
    if(!ruleExists){
        _itemsStatus[TypeStatus::translateTextType(getItemAt(typePos).getType())] = Status::NOTHING;
    }
}

void Board::updateItemsStatus(){
    updateRules();
    ////////////////////////////////////////////////////////////////////
    /// TODO; update this algo to set all items in the same squate !!!
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j < 19; j++) {
            for (unsigned int t = 0; t < _array[i][j].getAllItems().size(); ++t) {
                _array[i][j].getAllItems()[t].setStatus(_itemsStatus[_array[i][j].getAllItems()[t].getType()]);
            }
//            _array[i][j].getTopItem().setStatus(_itemsStatus[_array[i][j].getTopItem().getType()]);
        }
    }
}

void Board::updateMovableItems(){
    findTypeTexts();
    _movableItems.clear();
    Type type;
    for (const auto& pair : _itemsStatus) {
        if (pair.second == Status::MOVE) {
            type = pair.first;
            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < 20; j++) {
                    if(_array[i][j].getTopItem().getType() == type){
                        _movableItems.push_back(_array[i][j].getTopItem());
                    }
                }
            }
            break;
        }
    }
}

void Board::findTypeTexts(){
    this->_textTypeItems.clear();
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if(_array[i][j].getTopItem().getType() == Type::TEXT_WALL
                    || _array[i][j].getTopItem().getType() == Type::TEXT_BABA
                    || _array[i][j].getTopItem().getType() == Type::TEXT_ROCK
                    || _array[i][j].getTopItem().getType() == Type::TEXT_WATER
                    || _array[i][j].getTopItem().getType() == Type::TEXT_FLAG){
                this->_textTypeItems.push_back(_array[i][j].getTopItem());
            }
        }
    }
    updateItemsStatus();
}

std::vector<Item> &Board::getMovables(){
    return this->_movableItems;
}

bool Board::isInside(Position position) {
    if(position.getX() < 0 || position.getX()-1 > this->_rows) {
        return false;
    } else if(position.getY() < 0 || position.getY()-1 > this->_cols) {
        return false;
    }
    return true;
}

bool Board::isWin(){
    return this->_win;
}

void Board::setWin(bool b){
    this-> _win = b;
}
