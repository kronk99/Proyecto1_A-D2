//
// Created by huevitoentorta on 13/04/23.
//

#ifndef PROYECTO1_A_D2_BULLET_H
#define PROYECTO1_A_D2_BULLET_H
#include <iostream>
using namespace std;
#include "Bcollector.h"


#include <cstddef>

class Bullet {
private:
    int posx;
    int posy;
    //falta la posx del tamaño de la imagen
    //falta la posy del tamaño de la imagen (colisiones)
    Bullet* next;
public:
    Bullet();
    Bullet* getNext();
    void setNext(Bullet* nextbullet);

    int getPosx() const;

    void setPosx(int posx);

    int getPosy() const;

    void setPosy(int posy);
    void* operator new(size_t size);
};


#endif //PROYECTO1_A_D2_BULLET_H
