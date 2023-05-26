#pragma once

#include <game.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    SDL_FRect *frame;
    SDL_Texture *texture;
} Entity;

Entity initEntity(SDL_FRect p_rect, SDL_Texture *p_texture);
void drawEntity(SDLGame *p_sdl_game, Entity *p_entity);
void updateEntity(Entity *p_entity, SDL_FRect p_rect);
void playerMove(Entity *p_entity);
