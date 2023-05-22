#include <main.h>

int main(int argc, char *argv[])
{
    GameState game_state = {false, false, false, false, false, false};
    GameWindow game_window = {NULL, NULL, NULL, NULL};

    initSdl(&game_state);
    initWindow(&game_window, "Catty The Cat");

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
    }

    cleanUp(&game_window);

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

bool initWindow(GameWindow *p_game_window, const char *p_title)
{
    bool is_success = true;

    p_game_window->window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (p_game_window->window == NULL)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_CRITICAL, "[Failed to init SDL2 window: %s]\n", SDL_GetError());
        is_success = false;
    }

    p_game_window->renderer = SDL_CreateRenderer(p_game_window->window, -1, SDL_RENDERER_ACCELERATED);
    if (p_game_window->renderer == NULL)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to init SDL2 renderer: %s]\n", SDL_GetError());
        is_success = false;
    }

    return is_success;
}

void cleanUp(GameWindow *p_game_window)
{
    SDL_DestroyRenderer(p_game_window->renderer);
    SDL_DestroyTexture(p_game_window->texture);
    SDL_DestroyWindow(p_game_window->window);
}
