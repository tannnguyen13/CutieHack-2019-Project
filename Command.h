#ifndef CUTIEHACK_2019_PROJECT_COMMAND_H
#define CUTIEHACK_2019_PROJECT_COMMAND_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Command {
private:
	string commandWord;
	vector<string> commands;
public:
	Command(string);
	bool validCommand();
	void showAll();
	const string getCommandWord(); 
};

#endif