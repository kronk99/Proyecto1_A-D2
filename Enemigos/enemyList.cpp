//
// Created by huevitoentorta on 17/04/23.
//

#include "enemyList.h"

enemyList::enemyList(SDL_Renderer *renders) {
    this->size=0;
    render = renders;
    head = nullptr;
    current= nullptr;
}
void enemyList::insertFirst() {
    if(size != 0){ /**si el tamaño de la lista es diferente de 0*/
        enemigo *newnode = new enemigo("../textures/Spaceship.png",render); /**cree un nuevo nodo, sobrecargando la operacion new*/
        newnode->setnext(head); //el nodo siguiente es el head
        head = newnode;//cambia el head
        size++;
    }
    else{ /**si no, cree un nuevo nodo y asigneselo al puntero head*/
        this->head =new enemigo("../textures/Spaceship.png",render);
        size++;
    }
}

void *enemyList::getFirst() {
    return head;
}

void enemyList::deleteFirst() {
    current = head;
    if(head->getnext()!= NULL || size ==1){
        head = head->getnext();
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
int enemyList::getSIze() {
    return 0;
}

void enemyList::printList() {
    //va a recorrer la ruta y actualizar el movimiento asi como el updateRender;
}
void enemyList::moveNrender(){
    //int oleada = size;
    current=head;
    for(int a=0;a<=size;a++){
        current->update();
        current->renderAll();
        current=current->getnext();
    }
}
//OCUPO ACA UN METODO RENDER ALL QUE RECORRA LA LISTA Y RENDERIZE , CON UN CICLO FOR.
//Y ocupo tambien un metodo moveALL que recorra la lista y mueva el rectangulo

