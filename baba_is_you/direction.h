#ifndef DIRECTION_H
#define DIRECTION_H
#include <iostream>

class Direction{
    std::pair<int, int> right;
    std::pair<int, int> up;
    std::pair<int, int> left;
    std::pair<int, int> down;
};


//#include "position.h"

//enum class Direction{

// UP,DOWN,LEFT,RIGHT
//};

////constexpr Position::Position to_position(Direction d);

///*constexpr Position::Position to_position(Direction d){
//    return dir_to_pos[static_cast<int>(d)];
//}*/



#endif // DIRECTION_H
