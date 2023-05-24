#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int WINDOW_WIDTH = 640 * 1.5;
const int WINDOW_HEIGHT = 480 * 1.5;
const int PIXEL_WIDTH = 32 * 2;
const int PIXEL_HEIGHT = 32 * 2;
const int FPS = 60;
const int FRAME_DELAY = 1000 / FPS;
Uint32 FRAME_START = 0;
int FRAME_TIME = 0;

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

bool initSDL();
bool initWindow(SDLGame *p_sdl_game, const char *p_title);
void cleanUpSDL(SDLGame *p_sdl_game);

SDL_Texture *loadTexture(SDLGame *p_sdl_game, const char *p_path);

Entity initEntity(SDL_Rect p_rect, SDL_Texture *p_texture);
void drawEntity(SDLGame *p_sdl_game, Entity *p_entity);
void updateEntity(Entity *p_entity, SDL_Rect p_rect);
