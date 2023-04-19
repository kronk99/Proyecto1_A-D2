//
// Created by huevitoentorta on 17/04/23.
//

#include "enemyHndlr.h"

enemyHndlr::enemyHndlr(SDL_Renderer *renderer) {
    Fase1 = new enemyList[5]();
    Fase2 = new enemyList[5]();
    Fase3 = new enemyList[5]();
    FaseACt = 1;
    oleadaAct = 0;
    faseAct = Fase1;
    render = renderer;
}
enemyList enemyHndlr::getFase() {
    //falta evaluar caso donde ya el juego termina es decir
    //que vea a ver que retorna.
    changeFase();
    changeOleada();
    return faseAct[0];
    //retorna la fase en la lista de la oleada x;
}
//metodo que cambia la oleada actual de enemigos.
void enemyHndlr :: setOleada(int number){
    this->oleadaAct = number;
}
//metodo que cambia la fase del enemigo.
void enemyHndlr:: changeFase(){
    if (oleadaAct == 4 && faseAct[4].getFirst() == nullptr){
        cout<<"hay que cambiar de fase"<<endl;
        switch (FaseACt) {
            case 1:
                faseAct = Fase2;
                FaseACt++;
                cout<<"ahora la fase es 2"<<endl;
                oleadaAct = 0;
                break;
            case 2:
                faseAct = Fase3;
                FaseACt++;
                cout<<"ahora la fase es 3"<<endl;
                oleadaAct = 0;
                break;
            case 3:
                //win condition
                cout<<"winCon"<<endl;
                oleadaAct = 0;
                FaseACt = 0;
        }
    }
}
void enemyHndlr::changeOleada(){
    if(faseAct[oleadaAct].getFirst() == nullptr){
        cout<<"esta nulo"<<endl;
        if(oleadaAct!=4){
            oleadaAct++;
        }
        else{
            cout<<"hay que cambiar de fase"<<endl;
        }
    }
}

void enemyHndlr::buildEnemies() {//generador de enemigos de las 3 fases.
    for(int i=0;i<5;i++){
        random_device rd;
        std::uniform_int_distribution<int>randomx(1,10);
        int randomNUm = randomx(rd);
        cout<<"se van a crear "<<randomNUm<<"de enemigos"<<endl;
        Fase1[i].setRender(this->render);
        Fase1[i].createEnemyes(randomNUm);
    }
    cout<<"se creo la primera fase de enemmigos"<<endl;
    for(int i=0;i<5;i++){
        random_device rd;
        std::uniform_int_distribution<int>randomx(1,6);
        int randomNUm = randomx(rd);
        cout<<"se van a crear "<<randomNUm<<"de enemigos"<<endl;
        Fase2[i].setRender(this->render);
        Fase2[i].createEnemyes(randomNUm);
    }
    cout<<"se creo la 2 fase de enemmigos"<<endl;
    for(int i=0;i<5;i++){
        random_device rd;
        std::uniform_int_distribution<int>randomx(1,6);
        int randomNUm = randomx(rd);
        cout<<"se van a crear "<<randomNUm<<"de enemigos"<<endl;
        Fase3[i].setRender(this->render);
        Fase3[i].createEnemyes(randomNUm);
    }
    cout<<"sali de los 3 generadores de listas"<<endl;
}

int enemyHndlr::wincon() {
    return FaseACt;
}
