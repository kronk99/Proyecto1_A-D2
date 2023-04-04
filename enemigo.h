//
// Created by huevitoentorta on 01/04/23.
//

#ifndef PROYECTO1_A_D2_ENEMIGO_H
#define PROYECTO1_A_D2_ENEMIGO_H
#include <string>
using namespace std;
class enemigo {
private:
    string color;
    int vida;
    int pos_X;
    int pos_Y;
public:
    int getnumber();
    string getColor();
    int getVida();
    int getPosx();
    int getPosy();
};
#endif //PROYECTO1_A_D2_ENEMIGO_H
