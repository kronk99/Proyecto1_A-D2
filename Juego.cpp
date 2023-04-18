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
         //aca haga el switch case con el valor que retorna arduino handler
         //si es 0<1024 llame al metodo que cambia valor de las balas
         //si es  llame a move_u
    }
    cout<<a<<endl;
}
void Juego::setFlag() {
    flag=true;
}
