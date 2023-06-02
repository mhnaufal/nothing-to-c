#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static const int WINDOW_WIDTH = 640;
static const int WINDOW_HEIGHT = 480;
static const int PIXEL_WIDTH = 32 * 2;
static const int PIXEL_HEIGHT = 32 * 2;
static float GRAVITY = 0.18;

typedef struct GameState
{
    bool Menu;
    bool Instruction;
    bool Playing;
    bool Win;
    bool Lose;
    bool Exit;
} GameState;

typedef struct GameManager
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    TTF_Font *font;
} GameManager;

typedef struct TimeManager
{
    const int FPS;
    const int FRAME_DELAY;
    Uint32 FRAME_START;
    int FRAME_TIME;
} TimeManager;

/**************/
/*    Game    */
/**************/
void mainLoop(GameManager *p_game_manager, GameState game_state, TimeManager time_manager);
