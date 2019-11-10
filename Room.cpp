#include "Room.h"
using namespace std;
Room::Room() {
	this->description = "No";
	exits = new unordered_map<string, Room>;
	items = new unordered_map <string, Item>;
	npc = new unordered_map <string, Character>;
}

Room::Room(string description) {
	this->description = description;
	exits = new unordered_map<string, Room>;
	items = new unordered_map <string, Item>;
	npc = new unordered_map <string, Character>;
}

void Room::setLock(bool locked) {
	this->locked = locked;
}

void Room::unlock() {
	locked = false;
}

bool Room::checkLock() const {
	return locked;
}

void Room::setExit(string direction, Room* neighbor) {
	//exits->at(direction) = *neighbor;
	exits->insert({ direction, *neighbor });
}

void Room::setExit(string direction, Room neighbor) {
	//exits->at(direction) = neighbor;
	exits->insert({ direction, neighbor });
}

void Room::setNPC(string name, Character* person) {
	npc->insert({ name, *person });
}

Character Room::getNPC(const string name) {
	return npc->at(name);
}

bool Room::checkNPC() {
	return npc->empty();
}

void Room::removeItem(string name) {
	items->erase(name);
}

void Room::setItems(string name, Item* item) {
	//items->at(name) = *item;
	items->insert({ name, *item });
}

Item Room::getItems(string name) const {
	if (name == "sword") {
		return Item("sword", 15, 0, 0, 0);
	}
	else if (name == "shield") {
		return Item("shield", 0, 15, 0, 0);
	}
	else if (name == "necklace") {

	}
	else if (name == "health potion") {
		return Item("health potion", 0, 0, 15, 0);
	}
	else if (name == "mana potion") {
		return Item("mana potion", 0, 0, 0, 15);
	}	
	return Item("", 0,0,0,0);
}

bool Room::returnNPC(string name) {
	if (npc->find(name) != npc->end())
		return true;
	return false;
}

void Room::removeNPC(string name) {
	npc->erase(name);
}

string Room::getShortDescription() const {
	return description;
}

void Room::changeDescription(string description) {
	this->description = description;
}

bool Room::checkExits() {
	return exits->empty();
}

string Room::getLongDescription() const {
	return "You are now in the " + description + ".\n" + getExitString() + "\n" + getItems();
}

string Room::getExitString() const {
	string returnString = "Exits:";
	//unordered_map<string, Room>::iterator itr;
	for (auto itr = exits->begin(); itr != exits->end(); itr++) {
		returnString += itr->first + "    ";
	}
	return returnString;
}

string Room::getItems() const {
	string returnString = "Items:";
	//unordered_map<string, Item>::iterator itr;
	for (auto itr = items->begin(); itr != items->end(); itr++) {
		returnString += itr->first + "    ";
	}
	return returnString;
}

Room Room::getExit(string direction) const {
	auto room = exits->at(direction);
	return room;
}	