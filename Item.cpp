#include "Item.h"

using namespace std;

Item::Item(int str, int def, int hlth, int mna){
    strength = str;
    defense = def;
    health = hlth;
    mana = mna;
}

int Item::getStrength(){
    return strength;
}

int Item::getDefense(){
    return defense;
}

int Items:: getHealth() {
    return health;
}

int Item::getMana(); {
    return mana;
}

