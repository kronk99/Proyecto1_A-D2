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
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        cout<<"se inicio bien la libreria SDL"<<endl;
        window = SDL_CreateWindow(title , posx , posy ,width ,lenght , flags);
        cout<<"ventana creada exitosamente"<<endl;
        renderer = SDL_CreateRenderer(window , -1, 0);
        isRunning = true;
    }
    else{
        cout<<"no se creo bien la ventana de juego"<<endl;
        isRunning = false;
    }

}
void Game::update() {}
void Game::render() {}
void Game::eventHandler() {}
void Game::clean() {}
bool Game::running() {}
