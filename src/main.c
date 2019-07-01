#include "header.h"

int main()
{
    App *app = malloc(sizeof(App));
    initSDL(app);
    t_entity *backmain = createPlayer(app->renderer, "resources/backmain00.jpg");
    t_entity *player = createPlayer(app->renderer, "resources/comp4.png");
    t_entity **monsters = (t_entity **)malloc(sizeof(t_entity *) * 20);
    char *retryarr[4] = {"resources/01.jpg", "resources/02.jpg", "resources/03.jpg", "resources/04.jpg"};

    TTF_Init();
    TTF_Font *font = TTF_OpenFont("resources/ARIAL.TTF", 25);
    int texW = 0;
    int texH = 0;
    SDL_Color color = {0, 0, 0, 255};
    t_entity *background = createPlayer(app->renderer, "resources/background.jpg");
    background->x = 0;
    background->y = 0;
    SDL_Surface *scoresurface = TTF_RenderText_Solid(font, "Score: ", color);
    SDL_Texture *scoretexture = SDL_CreateTextureFromSurface(app->renderer, scoresurface);
    SDL_QueryTexture(scoretexture, NULL, NULL, &texW, &texH);
    SDL_Rect text = {10, 0, texW, texH};
    SDL_Rect textnum = {90, 0, 20, 30};

    int m = -1;
    int score = 0;
    int level = 1;
    char b[4];
    srand(time(NULL));
    t_entity *retry = NULL;
    SDL_Surface *scorenum = NULL;
    SDL_Texture *scoretexturenum = NULL;
    SDL_QueryTexture(scoretexturenum, NULL, NULL, &texW, &texH);
    char *test = NULL;
    while (monsters[++m])
    {
        if (m == 1 || m == 5 || m == 8 || m == 11)
            monsters[m] = createVirus(app->renderer, "resources/vir1.png");
        else if (m == 2 || m == 4 || m == 7 || m == 10)
            monsters[m] = createVirus(app->renderer, "resources/vir2.png");
        else
            monsters[m] = createVirus(app->renderer, "resources/vir3.png");
    }
    while (1)
    {
        while (1)
        {
            prepareScene(app->renderer);
            doInput(app);
            if (app->quit == 1)
                break;
            if (app->quit == 2)
                exit(1);
            blit(app, background->texture, background->x, background->y);
            presentScene(app->renderer);
            SDL_Delay(16);
        }
        prepareScene(app->renderer);
        blit(app, backmain->texture, 0, 0);
        doInput(app);
        if (app->up == 1)
            playerMoveUp(player);
        if (app->down == 1)
            playerMoveDown(player);
        if (app->left == 1)
            playerMoveLeft(player);
        if (app->right == 1)
            playerMoveRight(player);
        m = -1;
        while (monsters[++m])
        {
            renderEntity(app->renderer, monsters[m]);
            virusMoveDown(monsters[m], &level, &score);
            test = itoa(score, b);
            if (SDL_HasIntersection(player->rect, monsters[m]->rect))
            {
                if (score >= 0 && score <= 70)
                {
                    retry = createPlayer(app->renderer, retryarr[0]);
                    retry->x = 0;
                    retry->y = 0;
                }
                else if (score >= 71 && score <= 140)
                {
                    retry = createPlayer(app->renderer, retryarr[1]);
                    retry->x = 0;
                    retry->y = 0;
                }
                else if (score >= 141 && score <= 210)
                {
                    retry = createPlayer(app->renderer, retryarr[2]);
                    retry->x = 0;
                    retry->y = 0;
                }
                else
                {
                    retry = createPlayer(app->renderer, retryarr[3]);
                    retry->x = 0;
                    retry->y = 0;
                }
                while (1)
                {
                    prepareScene(app->renderer);
                    doInput(app);
                    blit(app, retry->texture, retry->x, retry->y);
                    SDL_Color colorRetry = {255, 255, 255, 255};
                    SDL_Rect textRetry = {1080, 570, texW, texH};
                    SDL_Rect textnumRetry = {1160, 570, 20, 30};
                    SDL_QueryTexture(scoretexture, NULL, NULL, &texW, &texH);                    
                    scoresurface = TTF_RenderText_Solid(font, "Score: ", colorRetry);
                    scoretexture = SDL_CreateTextureFromSurface(app->renderer, scoresurface);
                    scorenum = TTF_RenderText_Solid(font, test, colorRetry);
                    scoretexturenum = SDL_CreateTextureFromSurface(app->renderer, scorenum);
                    SDL_RenderCopy(app->renderer, scoretexture, NULL, &textRetry);
                    SDL_RenderCopy(app->renderer, scoretexturenum, NULL, &textnumRetry);
                    presentScene(app->renderer);
                    SDL_Delay(16);
                }
                exit(0);
            }
        }
        scorenum = TTF_RenderText_Solid(font, test, color);
        scoretexturenum = SDL_CreateTextureFromSurface(app->renderer, scorenum);
        SDL_RenderCopy(app->renderer, scoretexture, NULL, &text);
        SDL_RenderCopy(app->renderer, scoretexturenum, NULL, &textnum);
        renderEntity(app->renderer, player);
        presentScene(app->renderer);
        SDL_FreeSurface(scorenum);
        SDL_DestroyTexture(scoretexturenum);
        SDL_Delay(16);
    }

    cleanup(app);
    return 0;
}
