#include <main.h>

int main(int argc, char *argv[])
{
    GameState game_state = {false, false, false, false, false, false};
    GameWindow game_window = {NULL, NULL, NULL, NULL};

    initSdl(&game_state);
    initWindow(&game_window, "Catty The Cat");

    SDL_Delay(2000);
    return 0;
}

bool initSdl(GameState *p_game_state)
{
    bool is_success = true;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_CRITICAL, "[Failed to init SDL2: %s]\n", SDL_GetError());
        is_success = false;
    }

    p_game_state->Menu = true;
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "[Menu status: %d]\n", p_game_state->Menu);

    return is_success;
}

bool initWindow(GameWindow *p_game_window, const char *p_title)
{
    bool is_success = true;

    p_game_window->window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (p_game_window->window == NULL)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_CRITICAL, "[Failed to init SDL2 window: %s]\n", SDL_GetError());
        is_success = false;
    }

    return is_success;
}
