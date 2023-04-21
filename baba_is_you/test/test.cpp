#include "test.h"
#include "../game.h"
void run_Tests(){
    test_next_position();
    test_egal_operater_pos();
    test_egal_operater_item();
    test_on_stat_item();
    test_top_item();
    test_clear_square();
    test_remove_top_item();
    test_next_position_type();
    test_next_position_stat();
    test_update_movable_items();
    test_move();

}

//Test Position class
void test_next_position(){

        std::cout << "position tests : " << std::endl;
        bool test_passed = false;
        Position pos = Position(1,1);
        Position next_pos_up = Position(0,1);
        Position next_pos_down = Position(2,1);
        Position next_pos_left = Position(1,0);
        Position next_pos_right = Position(1,2);
        if(pos.nextPos(Direction::UP)== next_pos_up
                && pos.nextPos(Direction::DOWN)== next_pos_down
                && pos.nextPos(Direction::LEFT)== next_pos_left
                && pos.nextPos(Direction::RIGHT)== next_pos_right){
            test_passed =true;
        }
        if(test_passed){
            std::cout << "\t test next postition : OK" << std::endl;
        }else{
            std::cout << "\t test next postition : KO" << std::endl;
        }
}

void test_egal_operater_pos(){
    bool test_passed = false;
    Position pos1 = Position(1,1);
    Position pos2 = Position(1,1);
    if(pos1 == pos2){
        test_passed = true;
    }
    if(test_passed){
        std::cout << "\t test egal operater pos : OK" << std::endl;
    }else{
         std::cout << "\t test egal operater pos : KO" << std::endl;
    }

}

//Test Item class
void test_egal_operater_item(){
    std::cout << "item tests : " << std::endl;
    bool test_passed = false;
    Position pos1 = Position(1,1);
    Status stat1 = Status::PUSH;
    Type type1 = Type::BABA;
    Item item1 = Item(pos1,type1,stat1);
    Item item2 = Item(pos1,type1,stat1);
    if(item1 == item2){
        test_passed = true;
    }
    if(test_passed){
         std::cout << "\t test egal operater item : OK" << std::endl;
    }else {
         std::cout << "\t test egal operater item : KO" << std::endl;
    }

}
void test_on_stat_item(){
    bool test_passed = false;
    Position pos1 = Position(1,1);
    Status stat1 = Status::NOTHING;
    Type type1 = Type::BABA;
    Item item1 = Item(pos1,type1,stat1);
    Status stat2 = Status::PUSH;
    Item item2 = Item(pos1,type1,stat2);
    Status stat3 = Status::STOP;
    Item item3 = Item(pos1,type1,stat3);
    if(item1.isEmpty()&& !item1.isPushable()
            && !item1.isWinable() && !item1.isKiller()
            && item2.isPushable() && !item2.isEmpty()
            && item3.isStop() && !item3.isSink()){
        test_passed = true;

    }
    if(test_passed){
        std::cout << "\t test on stat item : OK" << std::endl;
    }else{
      std::cout << "\t test on stat item : KO" << std::endl;
    }

}


//Test Square class
void test_top_item(){
    std::cout << "square tests : " << std::endl;
    bool test_passed = false;
    Position pos1 = Position(1,1);
    Status stat1 = Status::NOTHING;
    Type type1 = Type::BABA;
    Item item1 = Item(pos1,type1,stat1);
    Status stat2 = Status::PUSH;
    Item item2 = Item(pos1,type1,stat2);
    Status stat3 = Status::STOP;
    Item item3 = Item(pos1,type1,stat3);
    Square square = Square(item1);
    square.addItem(item2);
    square.addItem(item3);
    if(square.getTopItem() == item3){
        test_passed = true;
    }
    if(test_passed){
        std::cout << "\t test top item : OK" << std::endl;
    }else {
        std::cout << "\t test top item : KO" << std::endl;
    }
}
void test_clear_square(){
    bool test_passed = false;
    Position pos1 = Position(1,1);
    Status stat1 = Status::NOTHING;
    Type type1 = Type::BABA;
    Item item1 = Item(pos1,type1,stat1);
    Status stat2 = Status::PUSH;
    Item item2 = Item(pos1,type1,stat2);
    Status stat3 = Status::STOP;
    Item item3 = Item(pos1,type1,stat3);
    Square square = Square(item1);
    square.addItem(item2);
    square.addItem(item3);
    square.cleanSquare();
    if(square.getAllItems().empty()){
        test_passed = true;
    }
    if(test_passed){
        std::cout << "\t test clear square : OK" << std::endl;
    }else{
        std::cout << "\t test clear square : Ko" << std::endl;
    }


}
void test_remove_top_item(){
    bool test_passed = false;
    Position pos1 = Position(1,1);
    Status stat1 = Status::NOTHING;
    Type type1 = Type::BABA;
    Item item1 = Item(pos1,type1,stat1);
    Status stat2 = Status::PUSH;
    Item item2 = Item(pos1,type1,stat2);
    Status stat3 = Status::STOP;
    Item item3 = Item(pos1,type1,stat3);
    Square square = Square(item1);
    square.addItem(item2);
    square.addItem(item3);
    square.removeTopItem();
    if(square.getTopItem()==item2){
        test_passed = true;
    }

    if(test_passed){
        std::cout << "\t test remove top item : OK" << std::endl;
    }else{
        std::cout << "\t test remove top item : KO" << std::endl;
    }
}

//Test Board class
void test_next_position_type(){
    std::cout << "board tests : " << std::endl;
    bool test_passed = false;
    Level lvl = Level(0);
    Board board = Board(lvl);
    Position pos = Position(8,5);
    board.fillBoard(lvl.getMap());

    if(board.nextPosType(pos,Direction::DOWN) == Type::WALL){
        test_passed =true;
    }
    if(test_passed){
        std::cout << "\t test next pos type : OK" << std::endl;
    }else{
        std::cout << "\t test next pos type : KO" << std::endl;
    }
}
void test_next_position_stat(){
    bool test_passed = false;
    Level lvl = Level(0);
    Board board = Board(lvl);
    Position pos = Position(8,5);
    board.fillBoard(lvl.getMap());

    if(board.nextPosStatus(pos,Direction::DOWN) == Status::NOTHING){
        test_passed =true;
    }
    if(test_passed){
        std::cout << "\t test next pos state : OK" << std::endl;
    }else{
        std::cout << "\t test next pos state : KO" << std::endl;
    }
}
void test_update_movable_items(){
    bool test_passed = false;
    Level lvl = Level(0);
    Board board = Board(lvl);
    board.fillBoard(lvl.getMap());
    board.updateMovableItems();
    if(board.getMovables().size() == 1){
        test_passed =true;
    }
    if(test_passed){
        std::cout << "\t test update movable items : OK" << std::endl;
    }else{
        std::cout << "\t test pdate movable items : KO" << std::endl;
    }
}


//Test Game class
void test_move(){
    bool befor_move = false;
    bool after_move = false;
    Game game;
    Position initi_pos = Position(9,6);
    Position move_pos =Position(9,5);
    game.renderBoard();
    game.getBoard().updateMovableItems();
    Item item = game.getBoard().getMovables().at(0);
    if(item.getPosition() == initi_pos){
        befor_move = true;
    }
    game.move(Direction::LEFT);
    item = game.getBoard().getMovables().at(0);
        if(item.getPosition() == move_pos){
            after_move =true;
        }
        if(befor_move && after_move){
            std::cout << "\t test move : OK" << std::endl;
        }else{
            std::cout << "\t test move : OK" << std::endl;
        }
}
