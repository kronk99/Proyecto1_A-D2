//
// Created by huevitoentorta on 05/04/23.
//

#ifndef PROYECTO1_A_D2_ARDUINOHNDLR_H
#define PROYECTO1_A_D2_ARDUINOHNDLR_H
#include <iostream>
#include <csignal>
#include <unistd.h>
#include "libserial/SerialStream.h"
//#include <SDL2/SDL.h>
using namespace LibSerial;
using namespace std;

class arduinoHndlr {
private:
    SerialStream serial_stream ;
    bool flag ;

public:
    arduinoHndlr();
    void startHandler();
    void startThread(); //los threads van en gameclass
    void sendtoArduino(string dato);
    int receivefromArduino();
};


#endif //PROYECTO1_A_D2_ARDUINOHNDLR_H
