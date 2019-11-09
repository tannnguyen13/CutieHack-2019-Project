#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "print.h"

using namespace std;

void print::print() {
    string bruh;
    getline(cin, bruh);
    int delay = 200;
    for(int i = 0; i < bruh.size(); i++) {
        cout << bruh[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}