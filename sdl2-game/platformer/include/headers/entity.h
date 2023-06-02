#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <game.h>

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

/****************/
/*    Entity    */
/****************/
Entity initEntity(SDL_FRect p_rect, SDL_Texture *p_texture, Velocity v);
void drawEntity(GameManager *p_sdl_game, Entity *p_entity);
void updateEntity(Entity *p_entity, SDL_FRect p_rect);
void animateEntity(const char *p_animation_image, int p_animation_length);

/****************/
/*    Player    */
/****************/
void playerMove(Entity *p_entity, SDL_Event *p_event);
