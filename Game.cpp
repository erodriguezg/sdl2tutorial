#include <SDL2/SDL_mixer.h>
#include "Game.h"
#include "TextureManager.h"

Game::Game(const char *title, int width, int height, bool fullscreen) {
	std::cout << "Construyendo Game" << std::endl;
	int flags = 0;

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//graficas
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}

	//Initialize SDL_mixer
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		std::cerr << "Error iniciando Mix_OpenAudio" << std::endl;
	}

	player = new GameObject("res/tiles/pato.png", this->renderer);
}

Game::~Game() {
	std::cout << "destruyendo Game" << std::endl;
	Mix_CloseAudio();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update() {
	cnt++;
	this->player->update();
	std::cout << cnt << std::endl;
}

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);
	this->player->render();
	SDL_RenderPresent(renderer);
}

void Game::doLoop() {
	Uint32 frameStart;
	int frameTime;
	while (this->running()) {
		frameStart = SDL_GetTicks();
		this->handleEvents();
		this->update();
		this->render();
		this->playSounds();
		frameTime = SDL_GetTicks() - frameStart;
		if (FRAME_DELAY > frameTime) {
			SDL_Delay(FRAME_DELAY - frameTime);
		}
	}
}

void Game::playSounds() {
	this->player->playSounds();
}

