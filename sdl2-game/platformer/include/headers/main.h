#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const int PIXEL_WIDTH = 32 * 2;
const int PIXEL_HEIGHT = 32 * 2;

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
    SDL_Renderer *renderer;
} SDLGame;

typedef struct
{
    SDL_Rect *frame;
    SDL_Texture *texture;
} Entity;

bool initSdl();
bool initWindow(SDLGame *p_sdl_game, const char *p_title);
void cleanUp(SDLGame *p_sdl_game, Entity *entity);
SDL_Texture *loadTexture(SDLGame *p_sdl_game, Entity *entitty, const char *p_path);
void clearRenderer(SDLGame *p_sdl_game);
void displayRenderer(SDLGame *p_sdl_game, Entity *entity);
