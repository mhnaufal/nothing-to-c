#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 640 * 1.5
#define WINDOW_HEIGHT 480 * 1.5

enum KeyPressSurface
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

SDL_Window *global_window = NULL;
SDL_Surface *global_surface = NULL;
SDL_Surface *global_hw = NULL;
SDL_Surface* global_key_press[KEY_PRESS_SURFACE_TOTAL];
SDL_Surface* global_current_surface = NULL;

bool init();
bool load_media();
void close_game();
SDL_Surface *load_surface(char *path);
