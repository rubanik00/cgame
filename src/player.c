#include "header.h"

t_entity *createPlayer(SDL_Renderer *renderer, char *texture) {
	t_entity *player = malloc(sizeof(t_entity));
	player->rect = malloc(sizeof(SDL_Rect));
	player->rect->x = SCREEN_WIDTH / 2;
	player->rect->y = SCREEN_HEIGHT / 2;
	player->rect->w = PLAYER_WIDTH;
	player->rect->h = PLAYER_WIDTH;
	player->texture = IMG_LoadTexture(renderer, texture);
	return player;
}

void playerMoveUp(t_entity *player) {
	if (player->rect->y > 0)
		player->rect->y -= PLAYER_STEP;
}

void playerMoveDown(t_entity *player) {
	if (player->rect->y < SCREEN_HEIGHT - PLAYER_WIDTH)
		player->rect->y += PLAYER_STEP;
}

void playerMoveLeft(t_entity *player) {
	if (player->rect->x > 0)
		player->rect->x -= PLAYER_STEP;
}

void playerMoveRight(t_entity *player) {
	if (player->rect->x < SCREEN_WIDTH - PLAYER_WIDTH)
		player->rect->x += PLAYER_STEP;
}
