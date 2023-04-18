//
// Created by huevitoentorta on 13/04/23.
//

#ifndef PROYECTO1_A_D2_BLIST_H
#define PROYECTO1_A_D2_BLIST_H
#include <iostream>
#include "Bnode.h"

using namespace std;

class BList {
private:
    Bnode *head;
    Bnode *current;
    int size;
public:
    BList();
    void insertFirst(void* pointer);
    void* getFirst();
    void deleteFirst();
    int getSIze();
    void printList();

};


#endif //PROYECTO1_A_D2_BLIST_H
