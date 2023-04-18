//
// Created by huevitoentorta on 13/04/23.
//

#ifndef PROYECTO1_A_D2_BNODE_H
#define PROYECTO1_A_D2_BNODE_H


class Bnode {
private:
    void *data; //quiza esto deba retornar un puntero de un puntero
    Bnode *nextptr= nullptr;
public:
    Bnode(void* data);
    Bnode* getNext();
    void setNext(Bnode* next);
    void* getData();
};


#endif //PROYECTO1_A_D2_BNODE_H
