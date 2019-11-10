#include "Parser.h"
using namespace std;

Parser::Parser() {
	commands = Command();
}

Command Parser::getCommand() {
	string inputLine;
	string word1 = "";
	string word2 = "";
	cout << "> ";
	getline(cin, inputLine);
	istringstream stream(inputLine);
	stream >> word1 >> word2;
	return Command(word1, word2);
}

void Parser::showCommands()
{
	commands.showAll();
}