#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int WINDOW_WIDTH = 640 * 1.2;
const int WINDOW_HEIGHT = 480 * 1.2;
const int PIXEL_WIDTH = 32;
const int PIXEL_HEIGHT = 32;

typedef struct
{
    bool Menu;
    bool Instruction;
    bool Playing;
    bool Win;
    bool Lose;
    bool Exit;
} GameState;

typedef struct
{
    SDL_Window *window;
    SDL_Window *surface;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
} SDLGame;

bool initSdl();
bool initWindow(SDLGame *p_sdl_game, const char *p_title);
void cleanUp(SDLGame *p_sdl_game);
SDL_Texture *loadTexture(SDLGame *p_sdl_game, const char *p_path);
void clearRenderer(SDLGame *p_sdl_game);
void displayRenderer(SDLGame *p_sdl_game);
