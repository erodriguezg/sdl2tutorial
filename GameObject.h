//
// Created by lalo on 14-05-18.
//

#ifndef SDL2TUTORIAL_GAMEOBJECT_H
#define SDL2TUTORIAL_GAMEOBJECT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

class GameObject {

public:
    GameObject(const char* texturesheet, SDL_Renderer* renderer);
    ~GameObject();

    void update();
    void render();
    void playSounds();

private:

    int tiles;
    int tileIndex, tileIndexAnt;

    int xPos;
    int yPos;

    Uint32 startTime;
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;

    Mix_Chunk* soundFx;

};


#endif //SDL2TUTORIAL_GAMEOBJECT_H
