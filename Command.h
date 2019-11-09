#ifndef CUTIEHACK_2019_PROJECT_COMMAND_H
#define CUTIEHACK_2019_PROJECT_COMMAND_H

#include "CommandWords.h"
#include <string>

using namespace std;

class Command {
private:
	CommandWord commandWord;
	string secondWord;
public:
	Command(CommandWord, string);
	const CommandWord getCommandWord()const ;
	const string getSecondWord() const;
	const bool isUnknown() const ;
	const bool hasSecondWord() const;
};

#endif