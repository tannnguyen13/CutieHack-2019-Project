//
// Created by Tann Nguyen on 11/9/19.
//

#ifndef CUTIEHACK_2019_PROJECT_PRINTER_H
#define CUTIEHACK_2019_PROJECT_PRINTER_H
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;
class Printer {
public:
    void print() {
        string thing;
        cin >> thing;
        int delay = 200;
        for(int i = 0; i < thing.size(); i++) {
            cout << thing[i] << flush;
            this_thread::sleep_for(chrono::milliseconds(delay));
        }
    }
};
#endif //CUTIEHACK_2019_PROJECT_PRINTER_H
