#include <iostream>
#include <string>
#include "Character.h"
#include "Combat.h"
#include "Command.h"
#include "Item.h"
#include "Parser.h"
#include "print.h"
#include "Room.h"
#include "Game.h"

using namespace std;
using namespace Print;

Game::Game() {
	parser = new Parser();
	mummy = new Character("Mummy", 30, 20, 1, 0, 35, 0, 0, 2, 1, 0, 5, true);
	slime = new Character("Slime", 50, 30, 2, 0, 55, 0, 10, 4, 2, 0, 8, true);
	minotaur = new Character("Minotaur", 80, 40, 3, 0, 70, 0, 10, 5, 6, 0, 12, true);
	skeleton = new Character("Skeleton", 40, 10, 1, 0, 40, 0, 0, 2, 0, 6, 8, true);
	finalBoss = new Character("Skeleton King", 120, 60, 4, 0, 80, 0, 15, 10, 10, 25, 15, true);
	key = new Item("key", 0, 0, 0, 0);
	cellKey = new Item("cellKey", 0, 0, 0, 0);
	sword = new Item("sword", 15, 0, 0, 0);
	shield = new Item("shield", 0, 15, 0, 0);
	healthPotion = new Item("health potion", 0, 0, 30, 0);
	manaPotion = new Item("meana potion", 0, 0, 0, 30);
	createRooms();
}

void Game::createRooms() {
	Room* tombs = new Room("tombs");
	Room* dungeon = new Room("dungeon");
	Room* guardroom = new Room("guardroom");
	Room* armory = new Room("armory");
	Room* storageroom = new Room("storageroom");
	Room* monsterroom = new Room("monsterroom");
	// create the rooms;
	mummyRoom = new Room("are in a fairly large room full of tombs. The one you woke up in seems to be vacant now that you have stepped out of it. There is a door to the north."); //room 1
	slimeRoom = new Room("are in a room full of cells. In these said cells, people are chained up and look hopeless. They call out to you to free them. There is a door to the north"); //room 2
	rpsDoor1 = new Room("are in a room with doors to the north, the east, the south, and the west. Guarding this room is an asleep orc that has several keys dangling from his belt."); // room 3
	minotaurRoom = new Room("are in a room filled to the brim with weapons, armor, and war-ready equipment."); // room 4
	rpsDoor2 = new Room("are in a room filled with sacks of supplies. You assume that at least some of these sacks are filled with food. You see some rope."); // room 5
	bigBossRoom = new Room("are in a room with a huge minotaur with a fierce axe. He looks particularly peeved and is ready to swing his axe. Past him seems to be the exit."); // room 6
	exit = new Room("are now in the exit of this dungeon. You do not know what is going on and who you are but you have made it out and ready to set out on your own adventure."); // finish the game

	// initialise room exits   
	// entrance & mummy -> room1, slime -> room 2, puzzle door lead to room 3, minotaur -> room 4, puzzle key -> big boss);

	//dungeon.setExit("north", dungeon);

	dungeon->setExit("north", guardroom);
	dungeon->setExit("south", tombs);

	guardroom->setExit("north", monsterroom);
	guardroom->setExit("west", armory);
	guardroom->setExit("east", storageroom);
	guardroom->setExit("south", dungeon);

	storageroom->setExit("west", guardroom);
	//storageroom->setItems("food", food);
	//storageroom->setItems("rope", rope);

	armory->setExit("east", guardroom);
	armory->setItems("sword", sword);
	armory->setItems("shield", shield);

	monsterroom->setExit("north", exit);
	monsterroom->setExit("south", guardroom);
	monsterroom->setLock(1);
	monsterroom->setNPC("minotaur", minotaur);

	currentRoom = armory;  // start game outside
}


void Game::printWelcome()
{
	cout << ("Welcome!");
	cout << ("Type 'help' if you need help.");
	/*cout << Long(" ");
	cout << Long(" ");
	cout << Long("...");
	cout << Long(" ");
	cout << Long(" ");
	cout << Long("...");
	cout << Long(" ");
	cout << Long(" ");*/
	cout << ("You wake up laying down in a dark place.") << endl;
	/*cout << Long(" ");
	cout << Long(" ");
	cout << Long("...");
	cout << Long(" ");
	cout << Long(" ");*/
	cout << ("After you realize you're conscious, you feel around. You seem to be confined in a rectangular shape. You push on the top of this 'box'.") << endl;
	//cout << Long(" ");
	cout << ("You are very weak but you manage to push the top off. You are greeted with a dull light. After you push the top off, you sit up.") << endl;
	//cout << Long(" ");
	cout << ("Sitting up, you realize that you are in a tomb. You don't know what to make of this.") << endl ;
	//cout << Long(" ");
	cout << ("You are very hungry right now.") << endl;
	//cout << Long(" ");
	//cout << Long(" ");
	//cout << (currentRoom.getLongDescription());
	cout << "fuck the current room description" << endl;
	cout << endl;
}


void Game::printHelp() {
	std::cout << "You are lost. You are alone. You wander" << endl;
	std::cout << "in this seemingly hopeless dungeon." << endl;
	cout << endl;
	cout << "Your command words are:" << endl;
	Command().showAll();
}

void Game::engage(Command command) {
	if (!command.hasSecondWord()) {
		cout << "Engage who?" << endl;
		return;
	}
	string name = command.getSecondWord();
	if (currentRoom->returnNPC(name)) {
		Character npc = currentRoom->getNPC(name);
		Combat* rpg = new Combat(p1, npc);
		rpg->engage();
	}
	else {
		cout << "You cannot engage that." << endl;
	}
}

void Game::goRoom(Command command)
{
	if (!command.hasSecondWord()) {
		// if there is no second word, we don't know where to go...
		cout << ("Go where?");
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room nextRoom = currentRoom->getExit(direction);

	if (nextRoom.getShortDescription() == "") {
		cout << ("You cannot go that way.") << endl;
	}
	else {
		if (!nextRoom.checkLock()) {
			if (currentRoom->checkNPC()) {
				*currentRoom = nextRoom;
				cout << ("You walk to the " + direction + " door. ");
				//cout << Long("");
				cout << currentRoom->getLongDescription() << endl;
				cout << "Current Status\n";
				p1->updateStatus();
			}
			else if (currentRoom->returnNPC("guard")) {
				if (currentRoom->getNPC("guard").checkTied()) {
					cout << ("You cannot go that way. The guard might be alerted if you just walk there!");
					return;
				}
				else {
					*currentRoom = nextRoom;
					cout << ("You walk to the " + direction + " door. ");
					//cout << Long("");
					cout << currentRoom->getLongDescription() << endl;
					cout << "Current Status\n";
					p1->updateStatus();
				}
			}
			else if (currentRoom->returnNPC("minotaur")) {
				if (currentRoom->getNPC("minotaur").getAlive()) {
					cout << ("You cannot get past the big minotaur.");
					return;
				}
				else {
					*currentRoom = nextRoom;
					cout << ("You walk to the " + direction + " door. ");
					//cout << Long("");
					cout << currentRoom->getLongDescription() << endl;
					cout << "Current Status\n";
					p1->updateStatus();
				}
			}
		}
		else {
			cout << ("That door is locked.");
		}
	}
	//p1->status();
}

bool Game::quit(Command command)
{
	if (command.hasSecondWord()) {
		cout << ("Quit what?");
		return false;
	}
	else {
		return true;  // signal that we want to quit
	}
}

//void attack(Command command) {
//	if (!command.hasSecondWord()) {
//		cout << ("Attack what?");
//		return;
//	}
//	int hit = rand.nextInt(100) + 1;
//	String name = command.getSecondWord();
//	if (currentRoom.returnNPC(name)) {
//		if (hit > (100 - p1.getHr())) {
//			int dmg = (p1.getAtk() - currentRoom.getNPC(name).getDf());
//			if (dmg < 0) {
//				dmg = 0;
//			}
//			currentRoom.getNPC(name).setHp(dmg);
//			if (p1.checkItem("sword")) {
//				cout << ("BOOM!");
//				cout << ("You have successfully hit the " + name + " with your sword for " + dmg + " damage!");
//			}
//			else {
//				cout << ("BOOM!");
//				cout << ("You have successfully punched the " + name + " for " + dmg + " damage!");
//			}
//			if (currentRoom.getNPC(name).getHp() < 1) {
//				currentRoom.removeNPC(name);
//				if (name.equals("guard")) {
//					cout << ("You have killed the orc guard.");
//					currentRoom.setItems("key", key);
//					currentRoom.setItems("cellkey", cellKey);
//					cout << ("The keys on his belt drop to the floor.");
//					cout << (currentRoom.getItems());
//					currentRoom.changeDescription("are in a room with a room to the north, the east, and the west. The orc guarding this room has been defeated.");
//				}
//				else if (name.equals("minotaur")) {
//					cout << ("You have killed the minotuar valiantly.");
//				}
//			}
//		}
//		else {
//			int dmg = (currentRoom.getNPC(name).getAtk() - p1.getDf());
//			if (dmg < 0) {
//				dmg = 0;
//			}
//			p1.setHp(dmg);
//			if (p1.checkItem("sword")) {
//				cout << ("SLAM!");
//				cout << ("You have missed trying to swing your sword at the " + name + " and it hits you for " + dmg + " damage!");
//			}
//			else {
//				cout << ("SLAM!");
//				cout << ("You missed your punch and " + name + " hits you for " + dmg + " damage!");
//			}
//		}
//	}
//	else {
//		cout << ("You cannot attack what is not in this room.");
//		return;
//	}
//	p1.updateStatus();
//	p1.status();
//	if (!currentRoom.checkNPC())
//		cout << (name + "'s HP: " + currentRoom.getNPC(name).getHp());
//
//}

void Game::grab(Command command) {
	if (!command.hasSecondWord()) {
		cout << ("Grab what?");
		return;
	}
	string item = command.getSecondWord();
	if (currentRoom->getItems(item).getString() != Item("", 0, 0, 0, 0).getString()) {
		p1->setItem(item, currentRoom->getItems(item));
		currentRoom->removeItem(item);
		cout << ("You have grabbed the " + item);
	}
	else {
		cout << ("That isn't in this room.");
		return;
	}
	//cout << (p1.getItemString());
}

void Game::equip(Command command) {
	if (!command.hasSecondWord()) {
		cout << ("Equip what?");
		return;
	}
	string item = command.getSecondWord();
	if (p1->checkEquip(item)) {
		if (item._Equal("sword")) {
			p1->equip(item);
			p1->addStrength(p1->getItem(item).getStrength());
			//p1->addHR();
			cout << ("You have equipped the sword. You feel stronger with this in your hand!");
		}
		else if (item._Equal("shield")) {
			p1->equip(item);
			p1->addDefense(p1->getItem(item).getDefense());
			cout << ("You have equpped the shield. You feel you can take a hit from anything!");
		}
		else if (item._Equal("necklace")) {
			p1->equip(item);
			cout << ("You have equipped the necklacke. You feel a new sense of arcane power in you.");
			p1->addMagic(10);
			p1->addMana(50);
		}
		else {
			cout << ("You cannot equip that.");
		}
	}
	else {
		cout << ("You cannot equip something that you don't have.");
		return;
	}
}

bool Game::processCommand(Command command)
{
	bool wantToQuit = false;
	string commandWord = command.getCommandWord();
	if (commandWord == "HELP") {
		printHelp();
		wantToQuit = true;
	}
	else if (commandWord == "GO") {
		goRoom(command);
		wantToQuit = true;
	}
	else if (commandWord == "QUIT") {
		wantToQuit = quit(command);
		return true;
	}
	else if (commandWord == "GRAB") {
		grab(command);
		wantToQuit = true;
	}
	else if (commandWord == "ENGAGE") {
		engage(command);
		wantToQuit = true;
	}
	else if (commandWord == "LOOK") {
		cout << (currentRoom->getLongDescription()) << endl;
		wantToQuit = true;
	}
	else if (commandWord == "SNEAK") {
		//sneak(command);
		return true;
	}
	else if (commandWord == "USE") {
		//use(command);
		wantToQuit = true;
	}
	else if (commandWord == "INVENTORY") {
		cout << (p1->getItemKey()) << endl;
		wantToQuit = true;
	}
	else if (commandWord == "EQUIP") {
		equip(command);
		wantToQuit = true;
	}
	else {
		cout << "I don't know what you mean..." << endl;
		wantToQuit = true;
	}
}

void Game::play() {
	string name;
	std::cout << "Please enter hero name: " << endl;
	cin >> name;
	p1 = new Character(name);
	//p1->startStamina();
	printWelcome();
	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the game is over.
	bool running = true;
	bool firstRun = true;
	while (running && p1->getAlive()) {
		if (firstRun) {
			cin.ignore();
			firstRun = false;
		}
		cout << "What do you want to do? " << endl;
		Command command = this->parser->getCommand();
		if (processCommand(command) || currentRoom->checkExits()) {
			
		}
		if (p1->getHP() < 1) {
			std::cout << "You have fallen in battle." << endl;
			running = false;
		}
	}
	
	std::cout << "Thank you for playing.  Good bye." << endl;
}

/**
 * cout <<  out the opening message for the player.
 */

/**
 * Given a command, process (that is: execute) the command.
 * @param command The command to be processed.
 * @return true If the command ends the game, false otherwise.
 */



int main() {
	Game* g1 = new Game();
	g1->play();
}