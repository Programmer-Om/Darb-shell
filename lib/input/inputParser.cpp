#include "inputParser.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



vector<string> Input_handler::input_getter(const string& shell_gui_prompt){
    cout << shell_gui_prompt;

    // Here you get/parse the input 
    string input_receiver_variable;
    getline(cin,input_receiver_variable);
    return input_parser(input_receiver_variable);
}

vector<string> Input_handler::input_parser(string input){
    /** 
     * - The next code adds the chars to compound_word variable and checks if it's a space/quote(single or double),
     * It detects if the space is inside the quotes or not so it should remove it or not , 
     * Then it Addeds it to the parsedInput vector .
     * 
    */
    stringstream input_separator(input);
    vector<string> parsedInput;
    // string word;
    string compound_word = "";
    int counter = 0;

    for (size_t i = 0; i < input.length(); i++){
        char char_in_position_i = input[i];
        

        if (char_in_position_i == '\'' && counter == 0){
            counter++;
        }
        else if (char_in_position_i == '\'' && !counter == 0){
            counter = 0;
        }
        else if (char_in_position_i == '"' && counter == 0){
            counter++;
        }
        else if (char_in_position_i == '"' && !counter == 0){
            counter = 0;
        }
        else if(isspace(char_in_position_i)){
            if (counter != 0){
                compound_word += char_in_position_i;
            } else if(!compound_word.empty())
            {
                parsedInput.push_back(compound_word);
                compound_word = "";
            }
            
        } else {
            compound_word += char_in_position_i;
        }
        

    }
    
    if (!compound_word.empty()) {
        parsedInput.push_back(compound_word);
    }


    return parsedInput;
}
