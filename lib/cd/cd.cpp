#include "cd.hpp"
#include <iostream>
#include <filesystem>

using namespace std;

void Change_Directory(string path) {
    try{
        if(path == "."){
        cout<<"Darb Shell : you are already in the route"<<endl;
    }else if (path==".."){
        filesystem::path parent_path = filesystem::current_path().parent_path();
        filesystem::current_path(parent_path);
    }else if(path == ""){
        filesystem::current_path("/");
    }else{
        if (filesystem::exists(path))
        {
            filesystem::current_path(path);
        }else{
            cout<<"No such path or directory"<<endl;
        }   
    }}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    
}