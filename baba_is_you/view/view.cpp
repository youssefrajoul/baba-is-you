#include <iostream>

#include "view.h"

View::View() {
    std::cout << "View Object Creation" << std::endl;
}

void View::printBoard(Game& game){
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            std::cout << " " << static_cast<char>(game
                                                  .getBoard()
                                                  .getArray()[i][j]
                                                  .getTopItem()
                                                  .getType());
            //            std::cout << "print board test" << std::endl;
        }
        std::cout << std::endl;
    }
}
