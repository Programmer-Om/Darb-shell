#include "inputParser.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> input_parser(string input){

    stringstream ss(input);
    vector<string> parsedInput;
    string word;

    while (ss >> word) {
        if(word.contains('\'') || word.contains('\"')){
           
                erase(word,'\"');
            
                erase(word,'\'');
                parsedInput.push_back(word);
               
        } else {
            parsedInput.push_back(word);    
        }
        }
    return parsedInput;
}
