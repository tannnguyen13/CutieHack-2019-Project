//
// Created by Tann Nguyen on 11/9/19.
//

#ifndef CUTIEHACK_2019_PROJECT_PARSER_H
#define CUTIEHACK_2019_PROJECT_PARSER_H

#include "CommandWords.h"
#include "Command.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

class Parser {
private:
    CommandWords commands;
public:
    Parser();
    Command getCommand();
    void showCommands();
};
#endif //CUTIEHACK_2019_PROJECT_PARSER_H
