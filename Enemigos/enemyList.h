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
    enemigo *current2;
    int size;
    int size2;
    SDL_Renderer* render;
public:
    enemyList();
    void insertFirst();
    enemigo* getFirst();
    enemigo* getFirstX();
    void deleteFirst();
    int getSIze();
    void printList();
    void moveNrender();
    void setRender(SDL_Renderer *renders);
    //un metodo checkcolision.
    void createEnemyes(int number);

    enemigo *search(int number);
};


#endif //PROYECTO1_A_D2_ENEMYLIST_H
