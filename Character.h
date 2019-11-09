#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>

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
        unordered_map<string, Item> inventory;
        unordered_map<string, Item> equipped;

    public:
        Character();
        Character(string n, double h, int mn, int lvl, int exp, int hR, double dmg, double crit, int def, int s, int mg, int str);
        const string getName() const;
        const double getHP() const;
        const int getMana() const;
        const int getLevel() const;
        const int getExperience() const;
        const double getHitRate() const;
        const double getDamageTaken() const;
        const double getCritChance() const;
        const int getDefense() const;
        const int getSpeed() const;
        const int getMagic() const;
        const int getStrength() const;
        const bool getAlive() const;
        void increaseLvL();
        void takeDamage(double dmg);
        void addHP(double h);
        void addMana(int m);
        void addStrength(int s);
        void addMagic(int m);
        void addDefense(int d);
        void addHitRate(int d);
        void addCritChance(double c);
        void status();
        void equip();
        bool checkEquip();
        const Item getEquip(string n);
        const string print(); 
};

#endif;