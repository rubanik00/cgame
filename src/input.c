#include "header.h"
void doKeyDown(SDL_KeyboardEvent *event, App *app)
{
    if (event->keysym.scancode == SDL_SCANCODE_UP)
        app->up = 1;
    if (event->keysym.scancode == SDL_SCANCODE_DOWN)
        app->down = 1;
    if (event->keysym.scancode == SDL_SCANCODE_LEFT)
        app->left = 1;
    if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
        app->right = 1;
	if (event->keysym.scancode == SDL_SCANCODE_Q)
		app->quit = 1;
}

void doKeyUp(SDL_KeyboardEvent *event, App *app)
{
    if (event->keysym.scancode == SDL_SCANCODE_UP)
        app->up = 0;
    if (event->keysym.scancode == SDL_SCANCODE_DOWN)
        app->down = 0;
    if (event->keysym.scancode == SDL_SCANCODE_LEFT)
        app->left = 0;
    if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
        app->right = 0;
     if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
        app->right = 0;
}
void doMsDown(SDL_MouseButtonEvent *event, App *app) {
	if (event->x >= 130 && event->x <= 330
	 && event->y >= 550 && event->y <= 630) {
		app->quit = 1;
	}
	if (event->x >= 1050 && event->x <= 1230
	&& event->y >= 570 && event->y <= 620) {
		app->quit = 2;
	}
}

void doInput(App *app) {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            cleanup(app);
            exit(0);
            break;
        case SDL_KEYDOWN:
            doKeyDown(&event.key, app);
            break;
        case SDL_KEYUP:
            doKeyUp(&event.key, app);
            break;
        case SDL_MOUSEBUTTONDOWN:
            doMsDown(&event.button, app);
            break;
        default:
            break;
        }
    }
}
