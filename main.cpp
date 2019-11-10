#include <iostream>
#include <string>
#include "Character.h"
#include "Combat.h"
#include "CombatWords.h"
#include "Command.h"
#include "CommandWords.h"
#include "Item.h"
#include "Parser.h"
#include "Printer.h"
#include "Room.h"


using namespace std;

Game::Game() {
    parser = new Parser()
    mummy new Character("Mummy", 30, 20, 1, 0, 35, 0, 0, 2, 1, 0, 5, true);
    slime = new Character("Slime", 50, 30, 2, 0, 55, 0, 10, 4, 2, 0, 8, true);
    minotaur = new Character("Minotaur", 80, 40, 3, 0, 70, 0, 10, 5, 6, 0, 12, true);
    skeleton = new Character("Skeleton", 40, 10, 1, 0, 40, 0, 0, 2, 0, 6, true); 
    finalBoss = new Character("Skeleton King", 120, 60, 4, 0, 80,0, 15, 10, 10, 25, 15, true);
    key = new Item(0, 0, 0, 0);
    cellKey = new Item(0, 0, 0, 0);
    sword = new Item(15, 0, 0, 0);
    shield = new Item(0, 15, 0, 0);
    healthPotion = new Item(0, 0, 30, 0);
    manaPotion = new Item(0, 0, 0, 30);
    //printer = new Print();
    createRooms(); 
}

void Game::createRooms() {
    Room tombs, dungeon, guardroom, armory, storageroom, monsterroom, exit; 
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
    dungeon.setExit("north", dungeon);
        
    dungeon.setExit("north", guardroom);
    dungeon.setExit("south", tombs);
        
    guardroom.setExit("north", monsterroom);
    guardroom.setExit("west", armory);
    guardroom.setExit("east", storageroom);
    guardroom.setExit("south", dungeon);
        
    storageroom.setExit("west", guardroom);
    storageroom.setItems("food", food);
    storageroom.setItems("rope", rope);
        
    armory.setExit("east", guardroom);
    armory.setItems("sword", sword);
    armory.setItems("shield", shield);
        
    monsterroom.setExit("north", exit);
    monsterroom.setExit("south", guardroom);
    monsterroom.setLock();
    monsterroom.setNPC("minotaur", minotaur);
        
    currentRoom = armory;  // start game outside
}

void Game::play(){
    string name;
    cout << "Please enter hero name: " << endl;
    cin >> name;
     p1 = new Player(name, 100, 50, 1, 0, 75, 0, 10, 8, 5, 10, 15, true);
        p1.startStamina();
        printWelcome();

        // Enter the main command loop.  Here we repeatedly read commands and
        // execute them until the game is over.
        bool finished = false;
        while (!finished && alive()) {
            Command command = parser.getCommand();
            if(processCommand(command) || currentRoom.checkExits()) {
            finished = true;
           }
        }
        if(p1.getHp() < 1) {
            printer.print("You have fallen in battle.");
        }
        printer.print("Thank you for playing.  Good bye.");
    }
    
    private boolean alive() {
        while(p1.getHp() > 0) {
        return true;
       }
       return false;
    }

    /**
     * printer.print out the opening message for the player.
     */
    private void printWelcome()
    {
        System.out.println();
        printer.print("Welcome!");
        printer.print("Type '" + CommandWord.HELP + "' if you need help.");
        printer.printLong(" ");
        printer.printLong(" ");
        printer.printLong("...");
        printer.printLong(" ");
        printer.printLong(" ");
        printer.printLong("...");
        printer.printLong(" ");
        printer.printLong(" ");
        printer.print("You wake up laying down in a dark place.");
        printer.printLong(" ");
        printer.printLong(" ");
        printer.printLong("...");
        printer.printLong(" ");
        printer.printLong(" ");
        printer.print("After you realize you're conscious, you feel around. You seem to be confined in a rectangular shape. You push on the top of this 'box'.");
        printer.printLong(" ");
        printer.print("You are very weak but you manage to push the top off. You are greeted with a dull light. After you push the top off, you sit up.");
        printer.printLong(" ");
        printer.print("Sitting up, you realize that you are in a tomb. You don't know what to make of this.");
        printer.printLong(" ");
        printer.print("You are very hungry right now.");
        printer.printLong(" ");
        printer.printLong(" ");
        printer.print(currentRoom.getLongDescription());
        p1.status();
    }

    /**
     * Given a command, process (that is: execute) the command.
     * @param command The command to be processed.
     * @return true If the command ends the game, false otherwise.
     */
    /*private boolean processCommand(Command command) 
    {
        boolean wantToQuit = false;

        CommandWord commandWord = command.getCommandWord();

        switch (commandWord) {
            case UNKNOWN:
                printer.print("I don't know what you mean...");
                break;

            case HELP:
                printHelp();
                break;

            case GO:
                goRoom(command);
                break;

            case QUIT:
                wantToQuit = quit(command);
                break;
                
            case GRAB:
                grab(command);
                break;
                
            case ENGAGE:
                engage(command);
                break;
                
            case LOOK:
                printer.print(currentRoom.getLongDescription());
                break;
                
            case SNEAK:
                sneak(command);
                break;
                
            case USE:
                use(command);
                break;
            
            case INVENTORY:
                printer.print(p1.getItemString());
                break;
                
            case EQUIP:
                equip(command);
                break;
        }
        return wantToQuit;*/
}

void Game::printHelp{
    printer.print("You are lost. You are alone. You wander");
    printer.print("in this seemingly hopeless dungeon.");
    System.out.println();
    printer.print("Your command words are:");
    parser.showCommands();
}

void Game::engage(Command command) {
    if(!command.hasSecondWord()) {
        printer.print("Engage who?");
            return;
        }
        String name = command.getSecondWord();
        if(currentRoom.returnNPC(name)) {
            Combat rpg = new Combat(p1, currentRoom.getNPC(name));
            rpg.engage();
        }
        else {
            printer.print("You cannot engage that.");
        }
}

void goRoom(Command command) 
    {
        if(!command.hasSecondWord()) {
            // if there is no second word, we don't know where to go...
            printer.print("Go where?");
            return;
        }

        String direction = command.getSecondWord();

        // Try to leave current room.
        Room nextRoom = currentRoom.getExit(direction);
        
        if (nextRoom == null) {
            printer.print("You cannot go that way.");
        }
        else {
            if(!nextRoom.checkLock()) {
                if(currentRoom.emptyNPC()) {
                    currentRoom = nextRoom;
                    printer.print("You walk to the " + direction + " door.");
                    printer.printLong("");
                    printer.print(currentRoom.getLongDescription());
                    p1.updateStatus();
                }
                else if(currentRoom.returnNPC("guard")){
                    if(!currentRoom.getNPC("guard").checkTied()) {
                        printer.print("You cannot go that way. The guard might be alerted if you just walk there!");
                        return;
                    }
                    else {
                        currentRoom = nextRoom;
                        printer.print("You walk to the " + direction + " door.");
                        printer.printLong("");
                        printer.print(currentRoom.getLongDescription());
                        p1.updateStatus();
                    }
                }
                else if(currentRoom.returnNPC("minotaur")) {
                    if(currentRoom.getNPC("minotaur").checkAlive()) {
                        printer.print("You cannot get past the big minotaur.");
                        return;
                    }
                    else {
                        currentRoom = nextRoom;
                        printer.print("You walk to the " + direction + " door.");
                        printer.printLong("");
                        printer.print(currentRoom.getLongDescription());
                        p1.updateStatus();
                    }
                }
            }
            else {
                printer.print("That door is locked.");
            }
        }
        p1.status();
    }

    boolean quit(Command command) 
    {
        if(command.hasSecondWord()) {
            printer.print("Quit what?");
            return false;
        }
        else {
            return true;  // signal that we want to quit
        }
    }

    void attack(Command command) {
        if(!command.hasSecondWord()) {
            printer.print("Attack what?");
            return;
        }
        int hit = rand.nextInt(100)+1;
        String name = command.getSecondWord();
        if (currentRoom.returnNPC(name)) {
            if(hit >(100 - p1.getHr())){
                int dmg = (p1.getAtk() - currentRoom.getNPC(name).getDf());
                if(dmg < 0) {
                    dmg = 0;
                }
                currentRoom.getNPC(name).setHp(dmg);
                if(p1.checkItem("sword")) {
                    printer.print("BOOM!");
                    printer.print("You have successfully hit the " + name + " with your sword for " + dmg + " damage!");
                }
                else {
                    printer.print("BOOM!");
                    printer.print("You have successfully punched the " + name + " for " + dmg + " damage!");
                }
                if(currentRoom.getNPC(name).getHp() < 1) {
                    currentRoom.removeNPC(name);
                    if(name.equals("guard")) {
                        printer.print("You have killed the orc guard.");
                        currentRoom.setItems("key", key);
                        currentRoom.setItems("cellkey", cellKey);
                        printer.print("The keys on his belt drop to the floor.");
                        printer.print(currentRoom.getItems());
                        currentRoom.changeDescription("are in a room with a room to the north, the east, and the west. The orc guarding this room has been defeated.");
                    }
                    else if(name.equals("minotaur")) {
                        printer.print("You have killed the minotuar valiantly.");
                    }
                }
            }
            else {
                int dmg = (currentRoom.getNPC(name).getAtk() - p1.getDf());
                if(dmg < 0) {
                    dmg = 0;
                }
                p1.setHp(dmg);
                if(p1.checkItem("sword")) {
                    printer.print("SLAM!");
                    printer.print("You have missed trying to swing your sword at the " +name + " and it hits you for " +dmg+ " damage!");
                }
                else {
                    printer.print("SLAM!");
                    printer.print("You missed your punch and " +name+ " hits you for " +dmg+ " damage!");
                }
            }
        }
        else {
            printer.print("You cannot attack what is not in this room.");
            return;
        }
        p1.updateStatus();
        p1.status();
        if(!currentRoom.checkNPC()) 
        printer.print(name + "'s HP: " + currentRoom.getNPC(name).getHp());
        
    }

    void grab(Command command) {
        if(!command.hasSecondWord()) {
            printer.print("Grab what?");
            return;
        }
        String item = command.getSecondWord();
        if(currentRoom.getItems(item) != null) {
            p1.setItem(item, currentRoom.getItems(item));
            currentRoom.removeItem(item);
            printer.print("You have grabbed the " +item);
        }
        else {
            printer.print("That isn't in this room.");
            return;
        }
        printer.print(p1.getItemString());
    }

    void equip(Command command) {
        if(!command.hasSecondWord()) {
            printer.print("Equip what?");
            return;
        }
        String item = command.getSecondWord();
        if(p1.checkItem(item)) {
            if(item.equals("sword")) {
                p1.equip(item);
                p1.addStrength(p1.getEq(item).getStrength());
                p1.addHR();
                p1.sword = true;
                printer.print("You have equipped the sword. You feel stronger with this in your hand!");
            }
            else if(item.equals("shield")) {
                p1.equip(item);
                p1.addDefense(p1.getEq(item).getDefense());
                p1.shield = true;
                printer.print("You have equpped the shield. You feel you can take a hit from anything!");
            }
            else if(item.equals("necklace")) {
                p1.equip(item);
                printer.print("You have equipped the necklacke. You feel a new sense of arcane power in you.");
            }
            else {
                printer.print("You cannot equip that.");
            }
        }
        else {
            printer.print("You cannot equip something that you don't have.");
            return;
        }
    }

    

