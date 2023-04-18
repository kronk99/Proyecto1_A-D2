//
// Created by huevitoentorta on 12/04/23.
//

#include "Lista.h"
Lista::Lista() {
    size = 0;
}
void Lista::insertFirst() {
    if(size != 0){ /**si el tamaño de la lista es diferente de 0*/
        Bullet *newnode = new Bullet(); /**cree un nuevo nodo, sobrecargando la operacion new*/
        newnode->setNext(head); //el nodo siguiente es el head
        head = newnode;//cambia el head
        size++;
    }
    else{ /**si no, cree un nuevo nodo y asigneselo al puntero head*/
        this->head =new Bullet();
        this->last = head;
        size++;
    }
}
void Lista::insertLast(){
    if(size != 0){ /**si el tamaño de la lista es diferente de 0*/
        Bullet *newnode = new Bullet(); /**cree un nuevo nodo, sobrecargando la operacion new*/
        last->setNext(newnode);
        last = newnode;
        size++;
        cout<<"se creo un nuevo bullet"<<endl;
    }
    else{ /**si no, cree un nuevo nodo y asigneselo al puntero head*/
        this->head =new Bullet();
        this->last = head;
        size++;
        cout<<"se creo un nuevo bullet"<<endl;
    }
}

void Lista::deleteFirst() { //caso donde un enemigo se golpea
    current = head;
    if(head->getNext()!= NULL || size ==1){
        head = head->getNext();
        cout<<"se va a eliminar una bala una bala:"<<endl;
        //totalmente o reciclarla.
        delete current; //deberia de sobrecargarse
        cout<<"se pudo pasar el delete de la lista"<<endl;
        size--;
    }
    else{
        cout<<"lista vacia"<<endl;
    }
}
void Lista::recicleBullet() {
    current = head;
    head = current->getNext();
    current->setNext(nullptr);
    //OJO ACA , VER SI ES NECESARIO CASTEARLO A VOID.
    Bcollector::getInstance()->addTrash(current);
    //caso donde la bala se sanlga de la pantalla
    size--;

}

void Lista::printList() {
    Bullet *currente = head;
    for(int i=0;i<size;i++){
        cout<< "la bala  es:"<< currente<<endl;
        currente=currente->getNext();
    }
}
void Lista::printCollector(){
    Bcollector::getInstance()->printList();
}
//me hace falta un metodo getFirst;
//hace falta un metodo Use bullet, que retorne el bullet
//y un metodo load bullet , que sea un metodo