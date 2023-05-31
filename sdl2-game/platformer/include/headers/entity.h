#pragma once

#include <game.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Velocity
{
    float x;
    float y;
} Velocity;

typedef struct Entity
{
    SDL_FRect *property;
    SDL_Texture *texture;
    Velocity velocity;
} Entity;

static int PLAYER_LIFE = 9;

Entity initEntity(SDL_FRect p_rect, SDL_Texture *p_texture, Velocity v);
void drawEntity(SDLGame *p_sdl_game, Entity *p_entity);
void updateEntity(Entity *p_entity, SDL_FRect p_rect);
void playerMove(Entity *p_entity, SDL_Event *p_event);
void animateEntity(const char *p_animation_image, int p_animation_length);
