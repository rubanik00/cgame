#include "header.h"

void initSDL(App *app) {	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}
	app->window = SDL_CreateWindow("Virus", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (!app->window) {
		printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(1);
	}
	app->renderer = SDL_CreateRenderer(app->window, -1, 0);    
	if (!app->renderer) {
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}
}

void cleanup(App *app) {	
	SDL_DestroyRenderer(app->renderer);
	SDL_DestroyWindow(app->window);
	SDL_Quit();
}
