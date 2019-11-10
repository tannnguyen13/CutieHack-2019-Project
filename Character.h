#ifndef CUTIEHACK_2019_PROJECT_CHARACTER_H
#define CUTIEHACK_2019_PROJECT_CHARACTER_H

#include <string>
#include <iostream>
#include <unordered_map>
#include "Item.h"

using namespace std;

class Character {
private:
	string name;
	double hp;
	double orighp;
	int mana;
	int level;
	int experience;
	int hitRate;
	double damageTaken;
	double critChance;
	int defense;
	int speed;
	int magic;
	int strength;
	bool alive;
	bool tied = false;
	unordered_map<string, Item>* inventory;
	unordered_map<string, Item>* equipped;

public:
	Character();
	Character(string n);
	Character(string n, double h, int mn, int lvl, int exp, int hR, double dmg, double crit, int def, int s, int mg, int str, bool a);
	const string getName() const;
	const double getHP() const;
	const double getMaxHP() const;
	const int getMana() const;
	const int getLevel() const;
	const int getExperience() const;
	const int getHitRate() const;
	const double getDamageTaken() const;
	const double getCritChance() const;
	const int getDefense() const;
	const int getSpeed() const;
	const int getMagic() const;
	const int getStrength() const;
	const bool getAlive() const;
	void increaseLvL(int exp);
	void takeDamage(double dmg);
	void addHP(double h);
	void addMana(int m);
	void addStrength(int s);
	void addMagic(int m);
	void addDefense(int d);
	void addHitRate(int h);
	void addCritChance(double c);
	void status();
	void equip(string n);
	bool checkEquip(string n);
	void changeSpeed(int s);
	bool checkTied();
	void changeTied();
	const Item getEquip(string n);
	void setItem(string, Item) {
		
	}
	void updateStatus() {
		cout << "Health: " << hp << endl;
		cout << "Mana: " << mana << endl;
	}
	Item getItem(string s) {
		if (s == "sword") {
			return Item("sword", 15, 0, 0, 0);
		}
		else if (s == "shield") {
			return Item("Shield", 0, 15, 0, 0);
		}
		else if (s == "necklace") {

		}
		else if (s == "health potion") {
			return Item("health potion", 0, 0, 15, 0);
		}
		else if (s == "mana potion") {
			return Item("mana potion", 0, 0, 0, 15);
		}
	}
	//const string print();
	string getItemKey() const;
};

#endif //CUTIEHACK_2019_PROJECT_CHARACTER_H
