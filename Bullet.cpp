//
// Created by huevitoentorta on 13/04/23.
//

#include "Bullet.h"

int Bullet::getPosx() const {
    return posx;
}

void Bullet::setPosx(int posx) {
    Bullet::posx = posx;
}

int Bullet::getPosy() const {
    return posy;
}

void Bullet::setPosy(int posy) {
    Bullet::posy = posy;
}

void *Bullet::operator new(size_t size) {
    if (Bcollector::getInstance()->getSize() != 0) {
        cout << "se recicla la memoria" << endl;
        Bullet *p = static_cast<Bullet *>(Bcollector::getInstance()->recoverP());
        cout << "se reciclo el puntero en memoria:" << p << endl;
        return p;
    } else {
        cout << "se crea un nuevo espacio en memoria" << endl;
        return ::new Bullet(); /**NEW GLOBAL */
    }
}

Bullet *Bullet::getNext() {
    return this->next;
}

void Bullet::setNext(Bullet *nextbullet) {
    this->next = nextbullet;

}

Bullet::Bullet() {

}
