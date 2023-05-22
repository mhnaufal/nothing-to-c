#include <main.h>

int main(int argc, char *argv[])
{
    GameState game_state = {false, false, false, false, false, false};
    SDLGame sdl_game = {NULL, NULL, NULL, NULL};

    initSdl();
    initWindow(&sdl_game, "Catty The Cat");

    loadTexture(&sdl_game, "./res/gfx/cat1.png");
    SDL_Event event;

    while (!game_state.Exit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                game_state.Exit = true;
            }
        }
        clearRenderer(&sdl_game);
        displayRenderer(&sdl_game);
    }

    cleanUp(&sdl_game);
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

void cleanUp(SDLGame *p_sdl_game)
{
    SDL_DestroyRenderer(p_sdl_game->renderer);
    SDL_DestroyTexture(p_sdl_game->texture);
    SDL_DestroyWindow(p_sdl_game->window);
}

SDL_Texture *loadTexture(SDLGame *p_sdl_game, const char *p_path)
{
    p_sdl_game->texture = IMG_LoadTexture(p_sdl_game->renderer, p_path);
    if (p_sdl_game->texture == NULL)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to load texture: %s]\n", SDL_GetError());
    }

    return p_sdl_game->texture;
}

void clearRenderer(SDLGame *p_sdl_game)
{
    SDL_RenderClear(p_sdl_game->renderer);
}

void displayRenderer(SDLGame *p_sdl_game)
{
    SDL_Rect src = {0, 0, PIXEL_WIDTH, PIXEL_HEIGHT};
    SDL_Rect dst = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, PIXEL_WIDTH, PIXEL_HEIGHT};

    SDL_RenderCopy(p_sdl_game->renderer, p_sdl_game->texture, &src, &dst);
    SDL_RenderPresent(p_sdl_game->renderer);
}
