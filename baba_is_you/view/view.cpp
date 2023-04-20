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
        }
        std::cout << std::endl;
    }
}
std::string View::askDirection(){
    std::cout << "Eter z for Up"<< std::endl;
    std::cout << "Eter s for Down"<< std::endl;
    std::cout << "Eter q for Lift"<< std::endl;
    std::cout << "Eter d for Right"<< std::endl;

    std::string d;
    std::cin >> d;
    std::cout << "Direction: "<< d << std::endl;
    return d;
}

void View::printlost(){
    std::cout<<"#### Sorry, You lost #### "<< std::endl;
    std::cout << "Enter 'r' to restart"<< "\n";
}
