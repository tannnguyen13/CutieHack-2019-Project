#include "Command.h"

Command::Command() {
	commandWord = "";
	secondWord = "";
	commands = { "GO", "QUIT", "HELP", "ENGANGE", "SNEAK", "GRAB", "USE", "LOOK", "INVENTORY", "EQUIP", "ATTACK", "DEFEND", "MAGIC" };
}

Command::Command(string commandWord) {
	this->commandWord = commandWord;
	secondWord = "";
	commands = { "GO", "QUIT", "HELP", "ENGANGE", "SNEAK", "GRAB", "USE", "LOOK", "INVENTORY", "EQUIP", "ATTACK", "DEFEND", "MAGIC" };
}

Command::Command(string commandWord, string secondWord) {
	this->commandWord = commandWord;
	this->secondWord = secondWord;
	commands = { "GO", "QUIT", "HELP", "ENGANGE", "SNEAK", "GRAB", "USE", "LOOK", "INVENTORY", "EQUIP", "ATTACK", "DEFEND", "MAGIC" };
}

bool Command::validCommand() {
	for (int i = 0; i < commands.size(); i++) {
		
		string temp = "";
		for (int j = 0; j < commands[i].size(); j++) {
			temp += tolower(commands[i].at(j));
		}
		if (commandWord == temp || commandWord == commands[i])
			return true;
	}
	return false;
}

void Command::showAll() {
	for (int i = 0; i < commands.size(); i++) {
		cout << commands[i] << " ";
	}
	cout << endl;
}

const string Command::getCommandWord(){
	for (int i = 0; i < commandWord.size(); i++) {
		commandWord[i] = toupper(commandWord[i]);
	}
	return commandWord;
}

bool Command::hasSecondWord() {
	return secondWord != "";
}

string Command::getSecondWord() {
	return secondWord;
}
 