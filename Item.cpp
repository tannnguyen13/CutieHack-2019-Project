#include <iostream>
#include "Item.h"

using namespace std;

Item::Item(int str, int def){
    strength = str;
    defense = def;
}

Item::getStrength(){
    return strength;
}

Item::getDefense(){
    return defense;
}

Items::setHealth(amount){
    health+= amount;
}

