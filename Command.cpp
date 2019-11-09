#include "Command.h"

Command::Command(CommandWord commandWord, string secondWord) {
	this->commandWord = commandWord;
	this->secondWord = secondWord;
}

const CommandWord Command::getCommandWord() const {
	return commandWord;
}

const string getSecondWord() const {
	return secondWord;
}

const bool isUnknown() const {
	return (commandWord == CommandWord.UNKNOWN);
}

const bool hasSecondaryWord() const {
	return (secondWord != "");
}