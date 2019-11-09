//
// Created by Tann Nguyen on 11/9/19.
//

#include "Parser.h"
using namespace std;

Parser::Parser() {
    commands = new CommandWords;
}

Command Parser::getCommand() {
    string inputLine;
    string word1 = "";
    string word2 = "";
    cout << "> ";
    getline(cin, inputLine);
    istringstream stream(inputLine);
    stream >> word1 >> word2;
    return new Command(commands.getCommandWord(word1), word2);
}

void Parser::showCommands()
{
    commands.showAll();
}