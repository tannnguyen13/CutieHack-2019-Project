//
// Created by Tann Nguyen on 11/9/19.
//

#ifndef CUTIEHACK_2019_PROJECT_COMBAT_H
#define CUTIEHACK_2019_PROJECT_COMBAT_H

#include "Character.h"
#include "Parser.h"
#include "Command.h"
#include "Printer.h"
#include <iostream>

class Combat {
private:
	Character player;
	Character enemy;
	void processCommand(string s);

public:
	Combat(Character&, Character&);
	void engage();
	void attack(); 

	void magic();
	void heal();
	void magicAttack();
	void debuff();

	void defend();
	void item();



	void enemyAttack();
	void enemyHeal();
	void enemyMagicAttack();
	void enemyMagicDebuff();
	void enemyDefend();
	void bestEnemyMove();

};

#endif //CUTIEHACK_2019_PROJECT_COMBAT_H
