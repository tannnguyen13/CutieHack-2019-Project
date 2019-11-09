//
// Created by Tann Nguyen on 11/9/19.
//
#include "Room.h"
using namespace std;
Room::Room(string description) {
    this.description = description;
    exits = new unordered_map<string, Room>;
    items = new unordered_map <string, Item);
    npc = new unordered_map <string, Character>;
}

void Room::setLock(bool locked) {
    this.locked = locked;
}

void Room::unlock() {
    locked = false;
}

bool Room::checkLock() const {
    return locked;
}

void Room::setExit(string direction, Room neighbor) {
    exits[direction] = neighbor;
}

void Room::setNPC(string name, Character person) {
    npc[name] = person;
}

void Room::getNPC(string name) const {
    return npc.find(name);
}

bool Room::checkNPC() {
    return npc.empty();
}

void Room::removeItem(string name) {
    items.erase(name);
}

void Room::setItems(string name, Item item) {
    items[name] = item;
}

Item Room::getItems(string name) const {
    return items.find(name);
}

bool Room::returnNPC(string name) {
    if(npc.find(name) != npc.end())
        return true;
    return false;
}

void Room::removeNPC(string name) {
    npc.erase(name);
}

string Room::getShortDescription() const {
    return description;
}

void Room::changeDescription(string description) {
    this.description = description;
}

bool Room::checkExits() {
    return exits.empty()
}

string Room::getLongDescription() const {
    return "You " + description + "\n" + getExitString() + ".\n" + getItems();
}

string Room::getExitString() const {
    string returnString = "Exits:";
    unordered_map<string, Room>:: iterator itr;
    for(itr = exits.begin(); itr < exits.end(); itr++) {
        returnString = itr->first + "    ";
    }
    return returnString;
}

string Room::getItems() const {
    string returnString = "Items:";
    unordered_map<string, Item>:: iterator itr;
    for(itr = items.begin(); itr < items.end(); itr++) {
        returnString = itr->first + "    ";
    }
    return returnString;
}

Room Room::getExit(string direction) const {
    return exits.find(direction);
}