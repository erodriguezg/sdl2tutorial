//
// Created by lalo on 14-05-18.
//

#include "TextureManager.h"

SDL_Texture *TextureManager::loadTexture(const char *fileName, SDL_Renderer *renderer) {
    SDL_Surface* tmpSurface = IMG_Load(fileName);
    SDL_SetColorKey(tmpSurface, SDL_TRUE, SDL_MapRGB(tmpSurface->format, 255, 0, 255));
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return texture;
}
