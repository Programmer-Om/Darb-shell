#pragma once
#include <iostream>
#include <sstream>
#include <vector>


class Input_handler {
private:
    std::vector<std::string> input_parser(std::string input);
public:
    /**
     * @param shell_gui_prompt The text that will be desplayed in the beginning of the line 
     * @return Vector of strings
     */
    std::vector<std::string> input_getter(const std::string& shell_gui_prompt);
};



