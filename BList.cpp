//
// Created by huevitoentorta on 13/04/23.
//

#include "BList.h"

void BList::insertFirst(void *pointer) {
    if(size != 0){ //si la lista ya tiene algo inserte de esta manera
        Bnode *newnode = new Bnode(pointer);
        newnode->setNext(head);
        head = newnode;
        size++;
    }
    else{/**si es el primer elemento , asignele el head el nuevonodo*/
        this->head = new Bnode(pointer);
        size++;
    }
}

void *BList::getFirst() {
    void *ptoReturn=static_cast<void *>(this->head->getData());
    deleteFirst(); //deberia de borrar el nodo de tipo GC
    return ptoReturn; //creo que esto causara problemas
}

BList::BList() {
    size = 0;
}

void BList::deleteFirst() {
    if(size != 0){
        current = head;
        head = head->getNext();
        delete(current);
        cout<<"borrado exitoso"<<endl;
        size--;
    }
    else{
        cout<<"no hay balas disponibles para retornar."<<endl;

    }
}

int BList::getSIze() {
    return this->size;
}

void BList::printList() {
    Bnode *currente = head;
    for(int i=0;i<size;i++){
        cout<< "el bullet de collector es:"<< currente->getData()<<endl;
        currente=currente->getNext();
    }
}
