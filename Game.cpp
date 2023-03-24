//
// Created by huevitoentorta on 18/03/23.
//

using namespace std;
#include "Game.h"
#include <iostream>
Game::Game() {
}
void Game::init(const char *title, int posx, int posy, int width, int lenght, bool fullscreen) {
    //este if asegura que sdl se inicie bien
    int flags = 0;
    if(fullscreen == true){
        flags = SDL_WINDOW_FULLSCREEN; //si se pide el juego en fullscreen se pone
    }
    if(SDL_Init(SDL_INIT_EVERYTHING)==0){//tal vez este if me jode la progra
        cout<<"se inicio bien la libreria SDL"<<endl;
        //debo de cambiar pos x posy a centrado por si no da buena imagen
        window = SDL_CreateWindow(title , posx , posy ,width ,lenght , flags);
        cout<<"ventana creada exitosamente"<<endl;
        renderer = SDL_CreateRenderer(window , -1, 0);
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        isRunning = true;
    }
    else{
        cout<<"no se creo bien la ventana de juego"<<endl;
        isRunning = false;
    }

}
void Game::update() {}
void Game::render() {
    /* render, a lo que entiendo que hace, es como un tazon donde se añaden cosas
     * ese "tazon" de cosas para renderizar , las presenta como una imagen completa
     * por lo que entiendo no lo "redibuja " por encima, de ahi el render clear
     * limpia lo que tiene ese tazon y render present, presenta en pantalla lo que
     * contenga render*/
    SDL_RenderClear(renderer);
    //aca es cuando le ponemos cosas a render, para que renderize en pantalla,
    SDL_RenderPresent(renderer);

}
void Game::eventHandler() { //no funciona de momento bien
    //funcion que maneja eventos
    SDL_Event evento ;
    //SDL_PollEvent(&evento); //investigar que hace esto
    while(SDL_PollEvent(&evento)){
        if(evento.type == SDL_QUIT || evento.type == SDL_WINDOWEVENT_CLOSE){
            isRunning = false;
        }
    }
    /*
    switch (evento.type) {
        //caso cuando le damos cerrar a la pestaña en la x, crea un evento
        //de tipo quit, si es quit, el siguiente loop del juego no va a ocurrir
        //y pone en falso running
        case SDL_QUIT: //si el evento es cerrar juego , corriendo es falso
            isRunning = false;
            cout<<"el evento es quit"<<endl;
            break;
        default:
            cout<<"no se hayo tipo de evento"<<endl;
            break;
    }*/
}
void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout<<"el juego se ha limpiado"<<endl;
}
bool Game::running() {
    return isRunning;
}
