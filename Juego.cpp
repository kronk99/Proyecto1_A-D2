//
// Created by huevitoentorta on 05/04/23.
//

#include "Juego.h"
Juego::Juego() {
    hndlr = new arduinoHndlr();
    hndlr->startHandler();
}
void Juego::receiveMsg() {
    int a;
    while(flag==true){
         a = hndlr->receivefromArduino();
    }
    cout<<a<<endl;
}
void Juego::setFlag() {
    flag=true;
}
