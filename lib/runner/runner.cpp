#include "runner.hpp"
#include "../input/inputParser.hpp"
#include "../cd/cd.hpp"
#include <unistd.h>
#include <sys/wait.h>
void run_shell_command(vector<string> arg){
    if(arg.size()<2){
        if(arg[0] == "cd")
    {   
        Change_Directory("/home/");
    }
    }else{
        Change_Directory(arg[1]);
    }
    
}

string run_command(vector<string> cmd){
    if (cmd.empty()) return "";

    pid_t cmd_execution = fork();
    if (cmd_execution == 0)
    {
        vector<char*> args;
        
        for (auto& word : cmd)
        {
            args.push_back(word.data());
        }

        args.push_back(nullptr);
        execvp(args[0],args.data());

        perror("execvp failed");
        _exit(1);

    }else if(cmd_execution > 0){
        int status;
        waitpid(cmd_execution,&status,0);
    }else{
        perror("Fork Failed");
    }
    
    return "";
}