#ifndef SDL2TUTORIAL_GAME_H
#define SDL2TUTORIAL_GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "GameObject.h"

class Game {
public:
	Game(const char *title, int width, int height, bool fullscreen);

	~Game();

	void doLoop();

private:

	static const int FPS = 60;
	static const int FRAME_DELAY = 1000 / FPS;

	SDL_Window *window;
	SDL_Renderer *renderer;
	GameObject *player;

	bool isRunning = false;
	int cnt = 0;

	void handleEvents();

	void update();

	bool running() {
		return isRunning;
	}

	void render();

	void playSounds();
};

#endif //SDL2TUTORIAL_GAME_H
