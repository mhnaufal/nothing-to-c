#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 640 * 1.5
#define WINDOW_HEIGHT 480 * 1.5

int main(int argc, char *argv[])
{
    // Initialize window
    SDL_Window *window = NULL;

    // Initialize surface
    SDL_Surface *surface = NULL;

    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to start SDL2: %s\n", SDL_GetError());
        return 1;
    }

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "SDL2 is ready!\n");

    // Create window
    window = SDL_CreateWindow("Platformer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "Failed to load the window: %s\n", SDL_GetError());
        return 1;
    }

    // Put on the surface
    surface = SDL_GetWindowSurface(window);

    // Fill the surface with white
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 16, 1, 61));

    SDL_Rect player;
    player.h = 100;
    player.w = 100;
    player.x = WINDOW_WIDTH / 2 - player.w / 2;
    player.y = WINDOW_HEIGHT / 2 - player.h / 2;

    SDL_FillRect(surface, &player, SDL_MapRGB(surface->format, 252, 7, 23));

    // Update the surface
    SDL_UpdateWindowSurface(window);

    SDL_Delay(1000);
    SDL_Rect enemy;
    enemy.h = 60;
    enemy.w = player.w * 4.5;
    enemy.x = WINDOW_WIDTH / 2 - enemy.w / 2;
    enemy.y = player.y - player.h / 2 - 20;
    SDL_FillRect(surface, &enemy, SDL_MapRGB(surface->format, 22, 225, 0));
    SDL_UpdateWindowSurface(window);

    // Make window stay still
    // SDL_Event e;
    // bool quit = false;
    // while (quit == false)
    // {
    //     while (SDL_PollEvent(&e))
    //     {
    //         if (e.type == SDL_Quit)
    //             quit = true;
    //     }
    // }
    SDL_Delay(3000);
    // sleep(1);

    // Clean up everything
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
