#ifndef CUTIEHACK_2019_PROJECT_ROOM_H
#define CUTIEHACK_2019_PROJECT_ROOM_H
#include <string>
#include <unordered_map>
#include "Item.h"
#include "Character.h"
#include <iostream>
using namespace std;

class Room {
	/*
	private String description;
	private HashMap<String, Room> exits;        // stores exits of this room.
	private HashMap<String, Item> items;
	private HashMap<String, Player> npc;
	private boolean locked = false;
	private boolean prisoners = false;
	 */
private:
	string description;
	unordered_map <string, Room>* exits;
	unordered_map <string, Item>* items;
	unordered_map <string, Character>* npc;
	bool locked;
public:
	Room();
	Room(string description);
	void setLock(bool locked);
	void unlock();
	bool checkLock() const;
	void setExit(string direction, Room* neighbor);
	void setExit(string direction, Room neighbor);
	bool emptyNPC();
	void setNPC(string name, Character* person);
	Character getNPC(const string name);
	bool checkNPC();
	void removeItem(string name);
	void setItems(string name, Item* item);
	Item getItems(string name) const;
	bool returnNPC(string name);
	void removeNPC(string name);
	string getShortDescription() const;
	void changeDescription(string description);
	bool checkExits();
	string getLongDescription() const;
	string getExitString() const;
	string getItems() const;
	Room getExit(string direction) const;
	bool operator==(Room& rhs) const {
		return this->description == rhs.description;
	}
};
#endif //CUTIEHACK_2019_PROJECT_ROOM_H