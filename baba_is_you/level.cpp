#include "level.h"
#include "status.h"
#include "type.h"

Level::Level(int level): _level(level){
    string filePath = "../baba_is_you/levels/level_" + std::to_string(this->_level) + ".txt";
    ifstream infile(filePath);
    if (!infile.is_open()) {
        cout << filePath << endl;
        cerr << "File could not be opened." << endl;
        exit(1);
    }

    string line, item, x, y;
    while (getline(infile, line)) {
        istringstream iss(line);
        if (!(iss >> item >> x >> y)) { // Check if all three words are present
            cerr << "Line does not have three words." << endl;
            break;
        }
        // Save the words into a vector and add it to the main vector
        vector<string> words = { item, x, y };
        _map.push_back(words);
    }

    infile.close(); // Close the file
}


std::vector<vector<std::string>> Level::getMap(){
    return this->_map;
}

std::pair<Type, Status> Level::translateFile(std::string word){
    Type type;
    Status status;
    if (word == "grass") {
        type = Type::GRASS;
        status = Status::STOP;
    }
    else if (word == "wall") {
        type = Type::WALL;
        status = Status::NOTHING;
    }
    else if (word == "metal") {
        type = Type::METAL;
        status = Status::NOTHING;

    }
    else if (word == "is") {
        type = Type::TEXT_IS;
        status = Status::PUSH;
    }
    else if (word == "flag") {
        type = Type::FLAG;
        status = Status::NOTHING;
    }
    else if (word == "stop") {
        type = Type::TEXT_STOP;
        status = Status::PUSH;
    }
    else if (word == "baba") {
        type = Type::BABA;
        status = Status::MOVE;
    }
    else if (word == "skull") {
        type = Type::SKULL;
        status = Status::NOTHING;
    }
    else if (word == "lava") {
        type = Type::LAVA;
        status = Status::KILL;
    }
    else if (word == "ice") {
        type = Type::ICE;
        status = Status::NOTHING;
    }
    else if (word == "rock") {
        type = Type::ROCK;
        status = Status::NOTHING;
    }
    else if (word == "text_rock") {
        type = Type::TEXT_ROCK;
        status = Status::PUSH;
    }
    else if (word == "water") {
        type = Type::WATER;
        status = Status::SINK;
    }
    else if (word == "text_flag") {
        type = Type::TEXT_FLAG;
        status = Status::PUSH;
    }
    else if (word == "win") {
        type = Type::TEXT_WIN;
        status = Status::PUSH;
    }
    else if (word == "push") {
        type = Type::TEXT_PUSH;
        status = Status::PUSH;
    }
    else if (word == "text_baba") {
        type = Type::TEXT_BABA;
        status = Status::PUSH;
    }
    else if (word == "text_wall") {
        type = Type::TEXT_WALL;
        status = Status::PUSH;
    }
    else if (word == "text_best") {
        type = Type::TEXT_BEST;
        status = Status::PUSH;
    }
    else if (word == "you") {
        type = Type::TEXT_YOU;
        status = Status::PUSH;
    }
    else if (word == "text_water") {
        type = Type::TEXT_WATER;
        status = Status::PUSH;
    }
    else if (word == "sink") {
        type = Type::TEXT_SINK;
        status = Status::PUSH;
    }else {
        type = Type::EMPTY;
        status = Status::NOTHING;
    }
    return std::make_pair(type, status);
}

int Level::getRows(){
    return std::stoi(this->_map[0][1]);
}

int Level::getCols(){
    return std::stoi(this->_map[0][2]);
}
