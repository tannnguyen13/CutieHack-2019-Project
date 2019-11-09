#include "Combat.h"

Combat::Combat(Character& player, Character& enemy) {
	this->player = player;
	this->enemy = enemy;
}

void Combat::processCommand(string s) {
	Command commandWord = Command(s);
	if(commandWord.getCommandWord() == "ATTACK"){
		if (player.getSpeed() > enemy.getSpeed()) {
			attack();
			bestEnemyMove();
			return;
		}
		else {
			bestEnemyMove();
			attack();
			return;
		}
	}
	else if(commandWord.getCommandWord() == "DEFEND"){
		if (player.getSpeed() > enemy.getSpeed()) {
			defend();
			bestEnemyMove();
			return;
		}
		else {
			bestEnemyMove();
			defend();
			return;
		}
	}
	else if(commandWord.getCommandWord() == "MAGIC") {
		if (player.getSpeed() > enemy.getSpeed()) {
			magic();
			bestEnemyMove();
			return;
		}
		else {
			bestEnemyMove();
			magic();
			return;
		}
	}
	else if (commandWord.getCommandWord() == "ITEM") {
		if (player.getSpeed() > enemy.getSpeed()) {
			item();
			bestEnemyMove();
			return;
		}
		else {
			bestEnemyMove();
			item();
			return;
		}
	}
	else {
			cout << "I don't know what you mean... " << endl;
	}
}

void Combat::engage() {
	cout << enemy.getName() << + " is battling you!" << endl;
	while (player.getAlive() && enemy.getAlive()) {
		cout << "ATTACK\n DEFEND\n MAGIC\n ITEM\n" << endl;
		string s = "";
		cin >> s;
		processCommand(s);
	}
}

void Combat::attack() {
	int hit = rand() % 100;
	if (hit > player.getHitRate()) {
		int temp = player.getStrength() - enemy.getDefense();
		double dmg = temp + rand() % 5;
		enemy.takeDamage(dmg);

		if (player.checkEquip("sword")) {
			cout << "SLASH" << endl;
			cout << "You Slash " << enemy.getName() << "for " << dmg << "damage!" << endl;
		}
		else if (player.checkEquip("fist")) {
			cout << "BAAM" << endl;
			cout << "You punch " << enemy.getName() << "for " << dmg << "damage!" << endl;
		}

	}
	else {
		cout << "WHOOSH" << endl;
		cout << "Your attack misses its mark!" << endl;
	}

	if (enemy.getHP() <= 0) {
		cout << "You have defeated the " << enemy.getName() << "!" << endl;
	}
}

void Combat::item() {
	cout << "What item do you want to use? " << endl;
	
}

void Combat::magicAttack() {
	if (player.getMana() >= 20) {
		int hit = rand() % 101;
		if (hit > player.getHitRate()) {
			int temp = player.getMagic() - enemy.getDefense();
			double dmg = temp + rand() % 5;
			enemy.takeDamage(dmg);
			cout << "You cast a fireball and hit " << enemy.getName() << " for " << dmg << "dmg." << endl;
		}
		else {
			cout << "Your fireball misses the enemy!" << endl;
		}
		cout << player.getName() << " Mana: -20" << endl;
		player.addMana(-20);
		if (enemy.getHP() <= 0) {
			cout << "You have defeated the " << enemy.getName() << endl;
		}
	}
	else {
		cout << "You attempt to cast a spell, but you are out of mana!" << endl;
	}
}

void Combat::heal() {
	if (player.getMana() >= 20) {
		cout << "You cast a heal spell!" << endl;
		player.addMana(-20);
		int heal = 8 + player.getMagic();
		cout << player.getName() << endl;
		cout << "Mana: -20 \t Health: +" << heal << "!" << endl;
		player.addHP(heal);
	}
	else {
		cout << "You attempt to use a heal spell, but you are out of mana!" << endl;
	}
}

void Combat::debuff() {
	if (player.getMana() >= 20) {
		int hit = rand() % 101;
		if (hit > player.getHitRate()) {
			enemy.changeSpeed(-2);
			cout << "You cast a debuff on the " << enemy.getName() << endl;
			cout << enemy.getName() << " Speed: -2\t Current Speed: " << enemy.getSpeed() << endl;
		}
		else {
			cout << "You attempt to cast a spell, but it fails!" << endl;
		}
		cout << player.getName() << " Mana: -20" << endl;
		player.addMana(-20);
	}
	else {
		cout << "You attempt to cast a debuff, but you did not have enough mana!" << endl;
	}
}

void Combat::magic() {
	if (player.getMana() >= 20) {
		cout << "Remaining Mana: " << player.getMana() << endl;
		cout << "What spell do you want to cast?" << endl;
		cout << "HEAL: 20mp\n FIREBALL: 20mp\n DEBUFF: 20mp" << endl;
		string s = "";
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			s = tolower(s[i]);
		}

		if (s == "HEAL") {
			heal();
		}
		else if (s == "FIREBALL") {
			magicAttack();
		}
		else if (s == "DEBUFF") {
			debuff();
		}
		else {
			cout << "You fumbled your words and failed to cast a proper spell!" << endl;
		}
	}
	else {
		cout << "You attempt to cast a spell, but do not have enough mana!" << endl;
	}
}

void Combat::defend() {
	cout << "You reinforce your defenses. " << endl;
	player.addDefense(player.getDefense() * 1.25);
}

void Combat::enemyAttack() {
	int hit = rand() % 101;
	if (hit > enemy.getHitRate()) {
		int temp = enemy.getStrength() - player.getDefense();
		double dmg = temp + rand() % 5;
		if (player.checkEquip("shield")) {
			cout << "TINK" << endl;
			cout << enemy.getName() << "attempts to hit you but you reflect the majority of the damage with your shield." << endl;
			dmg *= .2;
		}
		player.takeDamage(dmg);
		cout << "The" << enemy.getName() << " hits you for" << dmg << "dmg." << endl;
	}
	else {
		cout << "WHOOSH" << endl;
		cout << "The " << enemy.getName() << " tries to hit you but misses." << endl;
	}

	if (!player.getAlive()) {
		cout << "You have been defeated by the " << enemy.getName() << endl;
	}
}

void Combat::enemyMagicAttack() {
	if (enemy.getMana() >= 20) {
		int hit = rand() % 101;
		if (hit > enemy.getHitRate()) {
			int temp = enemy.getMagic() - player.getDefense();
			double dmg = temp + rand() % 5;
			if (player.checkEquip("shield")) {
				cout << "FWOOSH" << endl;
				cout << "The " << enemy.getName() << " throws a fireball towards your shield, causing the embers to spread and damage you directly!" << endl;
				dmg *= 7;
			}
			player.takeDamage(dmg);
			cout << enemy.getName() << " hits you for" << dmg << "dmg with their fireball" << endl;
		}
		else {
			cout << "WHOOSH" << endl;
			cout << "The " << enemy.getName() << "'s fireball wizzes by you head, missing you entirely. " << endl;
		}
		cout << enemy.getName() << " Mana: -20" << endl;
		enemy.addMana(-20);
		if (!player.getAlive()) {
			cout << "You have been defeated by the " << enemy.getName() << endl;
		}
	}
	else {
		cout << "The " << enemy.getName() << " attempts to cast a spell, but is out of mana!" << endl;
	}
}

void Combat::enemyMagicDebuff() {
	if (enemy.getMana() >= 20) {
		int hit = rand() % 101;
		if (hit > enemy.getHitRate()) {
			player.changeSpeed(-2);
			cout << "The " << enemy.getName() << " chants in an ancient language" << endl;
			cout << "You have been inflicted with a debuff!" << endl;
			cout << player.getName() << " Speed: -2\t Current Speed: " << player.getSpeed() << endl;
		}
		else {
			cout << "The " << enemy.getName() << " attempts to cast a spell, but fails!" << endl;
		}
		cout << enemy.getName() << " Mana: -20" << endl;
		enemy.addMana(-20);
	}
	else {
		cout << "The " << enemy.getName() << " attempts to cast a debuff, but did not have enough mana!" << endl;
	}
}

void Combat::enemyHeal() {
	if (enemy.getMana() >= 20) {
		cout << "The " << enemy.getName() << " casts a heal spell!" << endl;
		enemy.addMana(-20);
		int heal = 1 + rand() % 15;
		cout << enemy.getName() << endl;
		cout << " Mana: -20 \t Health: +" << heal << "!" << endl;
		enemy.addHP(heal);
	}
	else {
		cout << "The " << enemy.getName() << " attempts to use a heal spell, but was out of mana!" << endl;
	}
}


void Combat::enemyDefend() {
	cout << enemy.getName() << " raises their guard" << endl;
	enemy.addDefense(enemy.getDefense() * 1.25);
}

void Combat::bestEnemyMove() {
	
	double damageNorm = enemy.getStrength() - player.getDefense();
	double damageMagic = enemy.getMagic() - player.getDefense();
	if (player.checkEquip("shield")) {
		damageNorm *= .2;
		damageMagic *= .7;
	}

	if (enemy.getHP() > enemy.getMaxHP() / 5) {
		int attackPrioritize = rand() % 101;
		if (attackPrioritize > 10 && attackPrioritize < 30) {
			enemyDefend();
			return;
		}
		else if (attackPrioritize < 10 && enemy.getMana() >= 20) {
			enemyMagicDebuff();
		}
		else {
			if ((damageNorm > damageMagic) || enemy.getMana() < 20) {
				enemyAttack();
				return;
			}
			else {
				enemyMagicAttack();
				return;
			}
		}

	}
	else {
		if (enemy.getMana() >= 20) {
			int attackPrioritize = rand() % 101;
			if (attackPrioritize < 50) {
				enemyHeal();
				return;
			}
			else {
				if ((damageNorm > damageMagic) || enemy.getMana() < 20) {
					enemyAttack();
					return;
				}
				else {
					enemyMagicAttack();
					return;
				}
			}
		}
	}
}