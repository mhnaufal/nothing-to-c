#include <main.h>

int main(int argc, char *argv[])
{
    init();
    load_media();

    // Apply the image
    SDL_BlitSurface(global_hw, NULL, global_surface, NULL);
    SDL_UpdateWindowSurface(global_window);
    SDL_Delay(3000);

    close_game();

    return 0;
}

bool init()
{
    bool success = true;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to start SDL2: %s\n", SDL_GetError());
        return !success;
    }

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "SDL2 is ready!\n");

    // Create window
    global_window = SDL_CreateWindow("Platformer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (global_window == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "Failed to load the window: %s\n", SDL_GetError());
        return !success;
    }

    // Put on a surface to the window
    global_surface = SDL_GetWindowSurface(global_window);

    return success;
}

bool load_media()
{
    bool success = true;

    

    return success;
}

void close_game()
{
    SDL_FreeSurface(global_surface);
    global_hw = NULL;

    SDL_DestroyWindow(global_window);
    global_window = NULL;

    SDL_Quit();
}

SDL_Surface *load_surface(char *path)
{
    SDL_Surface *loaded_surface = SDL_LoadBMP(path);
    if (load_surface == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to load image to the screen: %s\n", SDL_GetError());
    }

    return load_surface;
}