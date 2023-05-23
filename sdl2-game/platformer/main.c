#include <main.h>

int main(int argc, char *argv[])
{
    initSdl();

    GameState game_state = {true, false, false, false, false, false};
    SDLGame sdl_game = {NULL, NULL};

    SDL_Rect entity_size = {WINDOW_WIDTH / 2 - PIXEL_WIDTH / 2, WINDOW_HEIGHT / 2 - PIXEL_HEIGHT, PIXEL_WIDTH, PIXEL_HEIGHT};
    Entity cat1 = {&entity_size, NULL};

    initWindow(&sdl_game, "Catty The Cat");

    loadTexture(&sdl_game, &cat1, "./res/gfx/cat1.png");
    SDL_Event event;

    while (!game_state.Exit)
    {
        FRAME_START = SDL_GetTicks();

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                game_state.Exit = true;
            }
        }
        clearRenderer(&sdl_game);
        displayRenderer(&sdl_game, &cat1);

        FRAME_TIME = SDL_GetTicks() - FRAME_START;

        if (FRAME_DELAY >= FRAME_TIME)
            SDL_Delay(FRAME_DELAY - FRAME_TIME);

        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "[FPS] %d\n", FRAME_TIME);
    }

    cleanUp(&sdl_game, &cat1);
    SDL_Quit();

    return 0;
}

bool initSdl()
{
    bool is_success = true;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_CRITICAL, "[Failed to init SDL2: %s]\n", SDL_GetError());
        is_success = false;
    }

    if (!(IMG_INIT_PNG))
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to init SDL2 Image for PNG: %s]\n", SDL_GetError());
        is_success = false;
    }

    return is_success;
}

bool initWindow(SDLGame *p_sdl_game, const char *p_title)
{
    bool is_success = true;

    p_sdl_game->window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (p_sdl_game->window == NULL)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_CRITICAL, "[Failed to init SDL2 window: %s]\n", SDL_GetError());
        is_success = false;
    }

    p_sdl_game->renderer = SDL_CreateRenderer(p_sdl_game->window, -1, SDL_RENDERER_ACCELERATED);
    if (p_sdl_game->renderer == NULL)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to init SDL2 renderer: %s]\n", SDL_GetError());
        is_success = false;
    }

    return is_success;
}

void cleanUp(SDLGame *p_sdl_game, Entity *entity)
{
    SDL_DestroyTexture(entity->texture);
    SDL_DestroyRenderer(p_sdl_game->renderer);
    SDL_DestroyWindow(p_sdl_game->window);
}

SDL_Texture *loadTexture(SDLGame *p_sdl_game, Entity *entitty, const char *p_path)
{
    entitty->texture = IMG_LoadTexture(p_sdl_game->renderer, p_path);
    if (entitty->texture == NULL)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to load texture: %s]\n", SDL_GetError());
    }

    return entitty->texture;
}

void clearRenderer(SDLGame *p_sdl_game)
{
    SDL_RenderClear(p_sdl_game->renderer);
}

void displayRenderer(SDLGame *p_sdl_game, Entity *entity)
{
    SDL_Rect src = {0, 0, entity->frame->w, entity->frame->h};
    SDL_Rect dst = {entity->frame->x, entity->frame->y, entity->frame->w, entity->frame->h};

    SDL_RenderCopy(p_sdl_game->renderer, entity->texture, &src, &dst);
    SDL_RenderPresent(p_sdl_game->renderer);
}
