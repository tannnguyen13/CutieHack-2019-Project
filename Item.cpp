#include "Item.h"

using namespace std;

Item::Item(string n, int str, int def, int hlth, int mna) {
	name = n;
	strength = str;
	defense = def;
	health = hlth;
	mana = mna;
}

string Item::getString() {
	return name;
}

int Item::getStrength() {
	return strength;
}

int Item::getDefense() {
	return defense;
}

int Item::getHealth() {
	return health;
}

int Item::getMana() {
	return mana;
}
