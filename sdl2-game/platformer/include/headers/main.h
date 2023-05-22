#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int WINDOW_WIDTH = 640 * 1.2;
const int WINDOW_HEIGHT = 480 * 1.2;

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
} GameWindow;

bool initSdl(GameState *p_game_state);
bool initWindow(GameWindow *p_game_window, const char *p_title);
void cleanUp();
