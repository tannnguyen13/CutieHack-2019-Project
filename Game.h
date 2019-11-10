#ifndef CUTIEHACK_2019_PROJECT_GAME_H
#define CUTIEHACK_2019_PROJECT_GAME_H
#include "Command.h"
#include "Parser.h"
using namespace std;

class Game {
public:
	Game();
	void play();

private:
	void createRooms();
	bool alive();
	void printWelcome();
	bool processCommand(Command);
	void printHelp();
	void engage(Command);
	void goRoom(Command);
	bool quit(Command);
	void attack(Command);
	void grab(Command);
	void sneak(Command);
	void use(Command);
	void equip(Command);

	Character* p1;

	Parser* parser;
	Character* mummy;
	Character* slime;
	Character* minotaur;
	Character* skeleton;
	Character* finalBoss;
	Item* key;
	Item* cellKey;
	Item* sword;
	Item* shield;
	Item* healthPotion;
	Item* manaPotion;

	Room* mummyRoom;
	Room* slimeRoom;
	Room* rpsDoor1;
	Room* minotaurRoom;
	Room* rpsDoor2;
	Room* bigBossRoom;
	Room* exit;
	Room* currentRoom;
};

#endif //CUTIEHACK_2019_PROJECT_ITEM_H