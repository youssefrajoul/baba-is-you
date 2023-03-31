#include "Level.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


Level::Level(int level){
    this->level = level;
}

std::vector<vector<string>> Level::getMap(){
    string filePath = "../baba_is_you/levels/level_" + std::to_string(this->level) + ".txt";
    cout << filePath << endl;
    ifstream infile(filePath); // Replace with your input file name
        if (!infile.is_open()) {
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
            map.push_back(words);
        }

        infile.close(); // Close the file


        return map;
}
