//
// Created by huevitoentorta on 13/04/23.
//

#include "Bcollector.h"
Bcollector* Bcollector::pointer= nullptr;
/**constructor no tiene tipo de dato*/
Bcollector::Bcollector(){ /**constructor de gcolector*/
    size = 0;
    lista = new BList();
}
/**tipo de dato , clase que pertenece, metodo*/
Bcollector* Bcollector:: getInstance(){ /**implementacion parcial de singleton para no tener que estar
    //creando instancias en cada nodo de node.h para sobrecargar new y delete.*/
    if(pointer== nullptr){
        cout<<"el gcolector estaba nulo"<<endl;
        pointer = new Bcollector();
        return pointer;
    }
    else{
        cout<<"ya esta creado el gcolector"<<endl;
        return pointer;
    }
}
//CUANDO USO ADDTRASH OCUPO CASTEARLO A VOID.
void Bcollector:: addTrash(void *pointer){ /*metodo que le añade el pointer a la lista del garbage collector*/
    lista->insertFirst(pointer);
    size++;
}
void * Bcollector::recoverP(){ /**metodo que regresa la data del nodo head de la lista de garbage collector*/
    return lista->getFirst();

}
int Bcollector::getSize(){ /**retorna el tamaño de la lista de garbage collector*/
    return lista->getSIze();
}
void Bcollector:: printList(){
    lista->printList();
}