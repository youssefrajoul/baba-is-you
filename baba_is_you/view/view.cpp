#include "view.h"

View::View() {
}

void View::WelcomeMessage(){
    std::cout << "------- BABA IS YOU -------" << std::endl;
    printHelp();
    std::cout << "MADE BY: YOUSSEF RAJOUL & TAREQ AHMED & PBT" << std::endl;
    std::cout << "Do you want Start from your last save y/n ?" << std::endl;
}

void View::printHelp(){
    std::cout << "Enter z/q/s/d to Move" << std::endl;
    std::cout << "Enter r to Restart" << std::endl;
    std::cout << "Enter u to Undo" << std::endl;
    std::cout << "Enter o to save your progress" << std::endl;
    std::cout << "Enter h to Show Help" << std::endl;
    std::cout << "Enter x to Exit" << std::endl;
}

void View::update(Observable* observable){
    Game* game = static_cast<Game*>(observable);
    printBoard(*game);
}

void View::printBoard(Game& game){
    printLevel(game.getLevel());
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
std::string View::askInput(){
    std::string d;
    std::cout << "Player Input: ";
    std::cin >> d;
    return d;
}

void View::printLevel(int level){
    std::cout << "--------------- Level: " << level+1 << " ---------------" << std::endl;
}

void View::printBye(){
    std::cout<<"#### Game Over, Bye #### "<< std::endl;
}

void View::printGameOver(){
    std::cout<<"#### Sorry, You lost #### "<< std::endl;
    std::cout << "Enter 'r' to restart"<< "\n";
}
