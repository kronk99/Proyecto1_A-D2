//
// Created by huevitoentorta on 01/04/23.
//

#include "enemigo.h"

int enemigo::getnumber() {
    return 0;
}
//hace falta un metodo buildship que le asigne la textura o color
//segun el atributo privado
string enemigo::getColor() {
    return this->color;
}

int enemigo::getVida() {
    return this->vida;
}

int enemigo::getPosx() {
    return this->pos_X;
}

int enemigo::getPosy() {
    return 0;
}

enemigo *enemigo::getnext() {
    return this->next;
}

void enemigo::setnext(enemigo* enemigos) {
    this->next = enemigos;
}

enemigo::enemigo(const char *texture, SDL_Renderer *renders) {
    render = renders;
    enemySkin=textureLoader::getTextureloader()->Loadtexture(texture , render);
    //estos posx pos y deben de ser a la izquierda de la imagen, y aleatorios
    pos_X=600;
    pos_Y=100;
    origen.x=0; //centro de la imagen
    origen.y=0;//centro de la imagen
    origen.h=351; //tamaño x de la imagen
    origen.w=198; //tamaño y de la imagen
}

void enemigo::update() {
    pos_X--;
    destino.x=pos_X; //esto deberia ser igual a la posx posy , el height y w se mantienen
    destino.y=pos_Y;//hasta donde mover la imagen
    destino.h=64;//reescalado de la imagen(la disminuye a 64 pixeles)
    destino.w=64;
}

void enemigo::renderAll() {
    SDL_RenderCopy(render,enemySkin,&origen,&destino);
}

const SDL_Rect * enemigo::getRect() {
    return &destino;
}
