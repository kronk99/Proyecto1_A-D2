//
// Created by huevitoentorta on 17/04/23.
//

#ifndef PROYECTO1_A_D2_ENEMYHNDLR_H
#define PROYECTO1_A_D2_ENEMYHNDLR_H
#include "enemyList.h"
#include <SDL2/SDL.h>

class enemyHndlr {
private:
    int oleadaAct;
    int FaseACt;
    SDL_Renderer* render;
    enemyList* Fase1;
    enemyList* Fase2;
    enemyList* Fase3;
    enemyList* faseAct;
    //enemyList enemigos[5];
public:
    enemyHndlr(SDL_Renderer *render);
    enemyList getFase();
    int wincon();
    void buildEnemies();
    void setOleada(int number);
    void changeFase();

    void changeOleada();
};


#endif //PROYECTO1_A_D2_ENEMYHNDLR_H
