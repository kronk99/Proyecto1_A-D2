//
// Created by huevitoentorta on 17/04/23.
//
#ifndef PROYECTO1_A_D2_ENEMYLIST_H
#define PROYECTO1_A_D2_ENEMYLIST_H
#include "enemigo.h"
#include <iostream>
using namespace std;
class enemyList {
private:
    enemigo *head;
    enemigo *current;
    int size;
    SDL_Renderer* render;
public:
    enemyList(SDL_Renderer* render);
    void insertFirst();
    void* getFirst();
    void deleteFirst();
    int getSIze();
    void printList();
    void moveNrender();
    //un metodo checkcolision.
};


#endif //PROYECTO1_A_D2_ENEMYLIST_H
