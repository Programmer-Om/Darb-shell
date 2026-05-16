#include "runner.hpp"
#include "../input/inputParser.hpp"
#include "../shell-commands/shell_commands.hpp"
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

void run_shell_command(vector<string> arg){
    if(arg[0] == "cd"){
        if(arg.size()<2){
            Change_Directory("/home/");
        }else{
            Change_Directory(arg[1]);
        }
    }else if(arg[0] == "darb"){
        if (arg.size()>1){
            Darb_shell(arg[1]);
        }else{
            Darb_shell();
        }
        
    }
    
}

string run_command(vector<string> cmd){
    if (cmd.empty()) return "";

    pid_t cmd_execution = fork();
    if (cmd_execution == 0) // Child process : executes the requested command 
    {
        vector<char*> args;
        
        for (auto& word : cmd)
        {
            args.push_back(word.data());
        }

        args.push_back(nullptr);  // execvp requires a null-terminated array
        execvp(args[0],args.data());

        // Error handler only if execvp failed
        perror("execvp failed");
        _exit(1);

    }else if(cmd_execution > 0){ // Parent process : waits for the child process to finish
                                 // before being able to receive any other commands
        int status;
        waitpid(cmd_execution,&status,0);
    }else{
        perror("Fork Failed");
    }
    
    return "";
}