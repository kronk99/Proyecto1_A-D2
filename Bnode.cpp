//
// Created by huevitoentorta on 13/04/23.
//

#include "Bnode.h"

Bnode::Bnode(void *data) {
    this->data= data;
}

Bnode *Bnode::getNext() {
    return this->nextptr;

}

void Bnode::setNext(Bnode *next) {
    this->nextptr = next;
}

void *Bnode::getData() {
    return this->data;
}
