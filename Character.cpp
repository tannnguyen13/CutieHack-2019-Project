#include <string>
#include <iostream>
#include "Character.h"

using namespace std;

Character::Character() {
    name = "none";
    hp = 0;
    orighp = 0;
    mana = 0;
    level = 0;
    experience = 0;
    hitRate = 0;
    damageTaken = 0;
    critChance = 0;
    defense = 0;
    speed = 0;
    magic = 0;
    strength = 0;
    alive = false;
}
Character::Character(string n, double h, int mn, int lvl, int exp, int hR, double dmg, double crit, int def, int s, int mg, int str, bool a) {
    name = n;
    hp = h;
    orighp = h;
    mana = mn;
    level = lvl;
    experience = exp;
    hitRate = hR;
    damageTaken = dmg;
    critChance = crit;
    defense = def;
    speed = s;
    magic = mg;
    strength = str;
    alive = a;
}

void Character::increaseLvL(int exp) {
    experience += exp;
    if (level == 1) {
        if (experience > 20)
            level++;
            experience -= 20;
    }else if ( level == 2) {
        if (experience > 40) {
            level++;
            experience -= 40;
        }
    }else if (level == 3) {
        if (experience >= 60) {
            level++;
            experience -= 60;

        }
    }else if (level == 4) {
        if (experience >= 80) {
            level++;
            experience -= 80;
        }
    }else if (level == 5) {
        if (experience >= 100) {
            return;
        }
    }
}

void Character::takeDamage(int dmg) {
    hp -= dmg;
}

void Character::addHP(double h) {
    hp += h;
}

void Character::addMana(int m) {
    mana += mn;
}

void Character::addStrength(int s) {
    strength += s;
}

void Character::addMagic(int m) {
    magic += m;
}

void Character::addDefense(int d) {
    defense += d;
}

void Character::addHitRate(double h) {
    hitrate += h;
}

void Character::addCritChance(double c) {
    critchance = critchance * (1 + c);
}

void Character::status() {
    cout << "HP: " << hp << "/" << orighp << endl;
    cout << "Mana: " << mn << endl;
}
void Character::equip(string n) {
    equipped.insert(name, inventory.erase(name));
}

bool Character::checkEquip(string n) {
    if (equipped.find(n) == equipped.end())
        return false;
    else
        return true;
}

const string Character::getName() const {
    return name;
}

const int Character::getHP() const{
    return hp;
}

const int Character::getMana() const {
    return mana;
}

const int Character::getLevel() const {
    return level;
}
        
const int Character::getExperience() const {
    return experience;
}

const int Character::getHitRate() const {
    return hitrate;
}
        
const int Character::getDamageTaken() const {
    return damageTaken;
}

const int Character::getCritChance() const {
    return critChance;
}

const int Character::getDefense() const {
    return defense;
}

const int Character::getSpeed() const {
    return speed;
}
        
const int Character::getMagic() const {
    return magic;
}
        
const int Character::getStrength() const {
    return strength;
}
    
const bool Character::getAlive() const {
    if (hp == 0) {
        return false;
    }
    return true;
}

const Item Character::getEquip(string n) {
    return equipped.at(n);
}
        
string Character::getItemKey const{
    string inventoryStr = "Inventory: ";
    unordered_map<string, Item>::iterator itr; 
    for (itr = inventory.begin(); itr != inventory.end(); itr++) { 
        inventoryStr += itr->first + ' ';
    }  

    string equippedStr = "Equipped: ";
    unordered_map<string, Item>::iterator itr; 
    for (itr = equipped.begin(); itr != equipped.end(); itr++) { 
        equippedStr += itr->first + ' ';
    }  

    return (inventoryStr + "\n" + equippedStr);
}
