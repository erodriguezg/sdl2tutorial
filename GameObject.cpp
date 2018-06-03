//
// Created by lalo on 14-05-18.
//
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>
#include <iostream>
#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *texturesheet, SDL_Renderer *renderer) {
    this->renderer = renderer;
    this->objTexture = TextureManager::loadTexture(texturesheet, this->renderer);
    this->tiles = 5;
    this->tileIndex = 0;
    this->tileIndexAnt = 0;

    this->soundFx = Mix_LoadWAV("res/sounds/cuak.wav");
    if(this->soundFx == NULL) {
        std::cerr <<  "Error cargando cuack.wav" << std::endl;
    }
}

GameObject::~GameObject() {
    Mix_FreeChunk(this->soundFx);
}

void GameObject::update() {

    tileIndexAnt = tileIndex;
    tileIndex = ((SDL_GetTicks() - startTime) * 4 / 1000) % tiles;

    xPos = 0;
    yPos = 0;

    srcRect.w = 20;
    srcRect.h = 20;
    srcRect.x = 20 * tileIndex;
    srcRect.y = 0;

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w * 10;
    destRect.h = srcRect.h * 10;

}

void GameObject::render() {
    SDL_RenderCopy(this->renderer, this->objTexture, &srcRect, &destRect);
}

void GameObject::playSounds() {

    if(tileIndex == 4 && tileIndexAnt == 3) {
        std::cout << "cuuuuaaaaak!   cuuuaakk!" << std::endl;
        Mix_PlayChannel(-1, this->soundFx, 0);
    }

}
