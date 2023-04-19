//
// Created by huevitoentorta on 17/04/23.
//

#include "enemyList.h"

enemyList::enemyList() {
    this->size=0;
    head = nullptr;
    current= nullptr;
    size2=0;
}
//hacer un metodo setRender y quitar el sdl renderer a enemyList
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
    current2=head;
}

enemigo* enemyList::getFirst() {
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
        current2=head;
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
    for(int a=0;a<size;a++){
        cout<<"moviendo el current"<<current<<endl;
        current->update();
        current->renderAll();
        current=current->getnext();
        //sera que tengo que meterle un render clean ?
    }
}
void enemyList::setRender(SDL_Renderer *renders){
    render =renders;
}

void enemyList::createEnemyes(int number) {
    for(int i=0;i<number;i++){
        insertFirst();

    }
    cout<<"se crearon"<<number<<"enemigos"<<endl;
}
enemigo *enemyList::getFirstX() {
    if(size2 <= size){
    }
}
enemigo *enemyList::search(int number) {
    current = head;
    for(int a=0;a<size;a++){
        current = current->getnext();
    }
    return current;
}
//OCUPO ACA UN METODO RENDER ALL QUE RECORRA LA LISTA Y RENDERIZE , CON UN CICLO FOR.
//Y ocupo tambien un metodo moveALL que recorra la lista y mueva el rectangulo

