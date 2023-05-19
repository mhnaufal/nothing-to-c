#pragma once

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 640 * 1.5
#define WINDOW_HEIGHT 480 * 1.5

SDL_Window *global_window = NULL;
SDL_Surface *global_surface = NULL;
SDL_Surface *global_hw = NULL;

bool init();
bool load_media();
void close_game();
