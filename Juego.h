//
// Created by huevitoentorta on 05/04/23.
//

#ifndef PROYECTO1_A_D2_JUEGO_H
#define PROYECTO1_A_D2_JUEGO_H
#include "arduinoHndlr.h"
#include <thread>

class Juego {
private:
    int gamemode;
    arduinoHndlr *hndlr;
    bool flag;
public:
    Juego();
    void setupThreads();
    void receiveMsg();
    void sendMsg();
    bool checkflag();
    void setFlag();
};
#endif //PROYECTO1_A_D2_JUEGO_H