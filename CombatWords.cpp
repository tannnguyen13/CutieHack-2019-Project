#include <iostream>
#include "CombatWords.h"

using namespace std;

    CombatWords::CombatWords(string cS){
        CommandString = cS;
    }
    string CombatWords::getCommandString(){
        return CommandString;
    }