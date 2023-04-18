//
// Created by huevitoentorta on 12/04/23.
//

#ifndef PROYECTO1_A_D2_LISTA_H
#define PROYECTO1_A_D2_LISTA_H
#include <iostream>
using namespace std;
#include "Bullet.h"

class Lista {
private:
    /**aca deberia de tener una instancia de garbage colector*/
    Bullet *head;
    Bullet *last;
    Bullet *current;
    int size;
public:
    Lista();
    void insertFirst();
    void insertLast();
    void deleteFirst();
    void printList();
    void recicleBullet();
    void printCollector();

};


#endif //PROYECTO1_A_D2_LISTA_H
