#ifndef CUTIEHACK_2019_PROJECT_ITEM_H
#define CUTIEHACK_2019_PROJECT_ITEM_H
#include <string>
using namespace std;


class CombatWords{
    public:
        CombatWords(string );
        string getCommandString();
    private:
        string commandString;
        string words[4] = {"attack", "defend", "magic", "item"};
};



#endif //CUTIEHACK_2019_PROJECT_ITEM_H
