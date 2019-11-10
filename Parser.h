#ifndef CUTIEHACK_2019_PROJECT_PARSER_H
#define CUTIEHACK_2019_PROJECT_PARSER_H
#include "Command.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

class Parser {
private:
	Command commands;
public:
	Parser();
	Command getCommand();
	void showCommands();
};
#endif //CUTIEHACK_2019_PROJECT_PARSER_H
