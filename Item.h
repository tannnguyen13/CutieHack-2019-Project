#ifndef CUTIEHACK_2019_PROJECT_ITEM_H
#define CUTIEHACK_2019_PROJECT_ITEM_H
#include <string>
using namespace std;

class Item{
    public:
        Item(int, int, int, int);
        int getStrength();
        int getDefense();
        int getHealth();
        int getMana();
    private:
        int strength;
        int defense;
        int health;
        int mana;
};



#endif //CUTIEHACK_2019_PROJECT_ITEM_H
