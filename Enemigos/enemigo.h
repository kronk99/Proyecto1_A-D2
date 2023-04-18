//
// Created by huevitoentorta on 01/04/23.
//

#ifndef PROYECTO1_A_D2_ENEMIGO_H
#define PROYECTO1_A_D2_ENEMIGO_H
#include <string>
#include <SDL2/SDL.h>
#include "../textureLoader.h"
using namespace std;
class enemigo {
private:
    string color;
    enemigo* next;
    int vida;
    int pos_X;
    int pos_Y;
    SDL_Texture* enemySkin;
    SDL_Rect origen , destino;
    SDL_Renderer* render;
public:
    enemigo(const char* texture , SDL_Renderer* renders);
    int getnumber();
    string getColor();
    int getVida();
    int getPosx();
    int getPosy();
    enemigo* getnext();
    void setnext(enemigo* enemigos);
    void update();
    void renderAll();
};
#endif //PROYECTO1_A_D2_ENEMIGO_H
