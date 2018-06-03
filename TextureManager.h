//
// Created by lalo on 14-05-18.
//

#ifndef SDL2TUTORIAL_TEXTUREMANAGER_H
#define SDL2TUTORIAL_TEXTUREMANAGER_H

#include <SDL2/SDL_image.h>

class TextureManager {

public:

    static SDL_Texture* loadTexture(const char* fileName, SDL_Renderer* renderer);

};


#endif //SDL2TUTORIAL_TEXTUREMANAGER_H
