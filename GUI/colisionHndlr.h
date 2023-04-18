//
// Created by huevitoentorta on 17/04/23.
//

#ifndef PROYECTO1_A_D2_COLISIONHNDLR_H
#define PROYECTO1_A_D2_COLISIONHNDLR_H

#include <SDL2/SDL.h>
class colisionHndlr {
//no se si tengo que hacer una unica instancia.
public:
    colisionHndlr();
    bool checkColision( SDL_Rect& rectA, SDL_Rect B);
    //hay que hacer un ciclo for doble
};


#endif //PROYECTO1_A_D2_COLISIONHNDLR_H
