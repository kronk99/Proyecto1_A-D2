//
// Created by huevitoentorta on 13/04/23.
//

#ifndef PROYECTO1_A_D2_BCOLLECTOR_H
#define PROYECTO1_A_D2_BCOLLECTOR_H
using namespace std;
#include <iostream>
#include "BList.h"
class Bcollector {
    BList *lista;
    int size;
    static Bcollector* pointer;
public:
    Bcollector();
    static Bcollector* getInstance();
    void addTrash(void *pointer);
    void* getData();
    void* recoverP();
    int getSize();
    void printList();
};


#endif //PROYECTO1_A_D2_BCOLLECTOR_H
