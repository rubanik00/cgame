#include "header.h"

t_entity *createVirus(SDL_Renderer *renderer, char *texture) {
    t_entity *virus = malloc(sizeof(t_entity));
	virus->rect = malloc(sizeof(SDL_Rect));
	virus->rect->x = rand() % SCREEN_WIDTH;
	virus->rect->y = (rand() % (-100 + 1 + 3000) - 3000);
	virus->rect->w = VIRUS_WIDTH;
	virus->rect->h = VIRUS_WIDTH;
	virus->texture = IMG_LoadTexture(renderer, texture);
	return virus;
}

void virusMoveDown(t_entity *virus, int *level, int *score)
{
	if (virus->rect->y > SCREEN_HEIGHT)
	{
		virus->rect->y = 0;
		virus->rect->x = rand() % SCREEN_WIDTH;
		(*score)++;
		if (*score >= 10 * *level)
			*level += 1;
	}
	virus->rect->y += 3 + *level;
}
