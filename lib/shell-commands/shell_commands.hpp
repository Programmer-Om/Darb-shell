#pragma once
#include <iostream>
#include <filesystem>
/** @file */
class Shell_commands {
public : 

    // move them here in future
};
/** @fn void Change_Directory(std::string path)
 * @param path Redirection Directory path
 * @fn void Darb_shell(std::string flag)
 * @param flag Darb command option
*/
void Change_Directory(std::string path);

void Darb_shell(std::string flag = "");