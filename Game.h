//
// Created by huevitoentorta on 18/03/23.
//

#ifndef PROYECTO1_A_D2_GAME_H
#define PROYECTO1_A_D2_GAME_H
//#include <SDL2/SDL.h> lo quito por que ya player.h lo incluye.
#include "Player.h"
#include "Enemigos/enemyList.h"
class Game {
private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    Player *player;
    enemyList* pruebaenemigo;
public:
    Game();
    void init(const char *title ,int posx , int posy , int width , int lenght ,bool fullscreen);
    void update();
    void render();
    void clean();
    void eventHandler();
    bool running();
};


#endif //PROYECTO1_A_D2_GAME_H
