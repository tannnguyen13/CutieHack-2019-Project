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
	equipped = new unordered_map<string, Item>;
	inventory = new unordered_map<string, Item>;
}

Character::Character(string n) {
	name = n;
	hp = 100;
	orighp = 100;
	mana = 100;
	level = 0;
	experience = 0;
	hitRate = 75;
	damageTaken = 0;
	critChance = 10;
	defense = 8;
	speed = 5;
	magic = 10;
	strength = 15;
	alive = true;
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
	}
	else if (level == 2) {
		if (experience > 40) {
			level++;
			experience -= 40;
		}
	}
	else if (level == 3) {
		if (experience >= 60) {
			level++;
			experience -= 60;

		}
	}
	else if (level == 4) {
		if (experience >= 80) {
			level++;
			experience -= 80;
		}
	}
	else if (level == 5) {
		if (experience >= 100) {
			return;
		}
	}
}

void Character::takeDamage(double dmg) {
	hp -= dmg;
}

void Character::addHP(double h) {
	hp += h;
}

void Character::addMana(int m) {
	mana += m;
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

void Character::addHitRate(int h) {
	hitRate += h;
}

void Character::addCritChance(double c) {
	critChance = critChance * (1 + c);
}

void Character::status() {
	cout << "HP: " << hp << "/" << orighp << endl;
	cout << "Mana: " << mana << endl;
}
void Character::equip(string n) {
//	equipped->insert(n, inventory->erase(n));

	//equipped->at(n);
	if (n == "sword") {
		inventory->erase(n);
		equipped->insert({ n, Item("sword", 15, 0,0,0) });
	}
	else if (n == "shield") {
		inventory->erase(n);
		equipped->insert({ n, Item("shield", 0, 15,0,0) });
	}
	
}

bool Character::checkEquip(string n) {
	if (n == "sword") {
		
	}
	else if (n == "shield") {

	}
	return false;
}

const string Character::getName() const {
	return name;
}

const double Character::getHP() const {
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
	return hitRate;
}

const double Character::getDamageTaken() const {
	return damageTaken;
}

const double Character::getCritChance() const {
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
	return equipped->at(n);
}

string Character::getItemKey() const{
	string inventoryStr = "Inventory: ";
	//unordered_map<string, Item>::iterator itr;
	for (auto i = inventory->begin(); i != inventory->end(); i++) {
		inventoryStr += i->first + ' ';
	}

	string equippedStr = "Equipped: ";
	//unordered_map<string, Item>::iterator itr;
	for (auto i = equipped->begin(); i != equipped->end(); i++) {
		equippedStr += i->first + ' ';
	}

	return (inventoryStr + "\n" + equippedStr);
}

void Character::changeSpeed(int s) {
	speed += s;
}

const double Character::getMaxHP() const{
	return orighp;
}

bool Character::checkTied() {
	return tied;
}

void Character::changeTied() {
	tied = !tied;
}