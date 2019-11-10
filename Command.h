#ifndef CUTIEHACK_2019_PROJECT_COMMAND_H
#define CUTIEHACK_2019_PROJECT_COMMAND_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Command {
private:
	string commandWord;
	string secondWord;
	vector<string> commands;
public:
	Command();
	Command(string);
	Command(string, string);
	bool validCommand();
	void showAll();
	const string getCommandWord(); 
	bool hasSecondWord();
	string getSecondWord();

};

#endif