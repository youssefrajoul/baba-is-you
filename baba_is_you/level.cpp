#include "level.h"


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

int Level::getRows(){
    return std::stoi(this->_map[0][1]);
}

int Level::getCols(){
    return std::stoi(this->_map[0][2]);
}
