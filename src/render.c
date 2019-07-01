#include "header.h"

void prepareScene(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 138, 197, 255);
	SDL_RenderClear(renderer);
}

void presentScene(SDL_Renderer *renderer) {
	SDL_RenderPresent(renderer);
}

void renderEntity(SDL_Renderer *renderer, t_entity *player) {			
	SDL_RenderCopy(renderer, player->texture, NULL, player->rect);
}

void blit(App *app, SDL_Texture *texture, int x, int y) {
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(app->renderer, texture, NULL, &dest);
}

