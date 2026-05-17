#include "shell_commands.hpp"
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

void Darb_shell(string flag){
    if (flag == "-v" || flag == "--version"){
        cout<<"Darb Shell version 0.2.0-alpha.0.3"<<endl;
    }else if (flag == "-h" || flag == "--help"){
        cout<< " -h  OR  --help : Displays this message"<<endl;
        cout<< " -v  OR  --version : Displays the current version of Darb Shell"<<endl;
    }else if (flag.empty()){
                cout<<endl;
                cout<<"██████╗  █████╗ ██████╗ ██████╗     ███████╗██╗  ██╗███████╗██╗     ██╗     "<<endl;
				cout<<"██╔══██╗██╔══██╗██╔══██╗██╔══██╗    ██╔════╝██║  ██║██╔════╝██║     ██║     "<<endl;
				cout<<"██║  ██║███████║██████╔╝██████╔╝    ███████╗███████║█████╗  ██║     ██║     "<<endl;
				cout<<"██║  ██║██╔══██║██╔══██╗██╔══██╗    ╚════██║██╔══██║██╔══╝  ██║     ██║     "<<endl;
				cout<<"██████╔╝██║  ██║██║  ██║██████╔╝    ███████║██║  ██║███████╗███████╗███████╗"<<endl;
				cout<<"╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝     ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝"<<endl;
    }
    else{
        cout<<"Wrong option"<<endl;
    }
    
}