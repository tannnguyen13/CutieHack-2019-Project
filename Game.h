#ifndef CUTIEHACK_2019_PROJECT_ITEM_H
#define CUTIEHACK_2019_PROJECT_ITEM_H

using namespace std;

class Game{
    public:
        Game::Game();
        void play();

    private:
        void createRooms();
        boolean alive();
        void printWelcome();
        boolean processCommand(Command);
        void printHelp();
        void engage(Command);
        void goRoom(Command);
        boolean quit(Command);
        void attack(Command);
        void grab(Command);
        void sneak(Command);
        void use(Command);
        void equip(Command);
        
};



#endif //CUTIEHACK_2019_PROJECT_ITEM_H