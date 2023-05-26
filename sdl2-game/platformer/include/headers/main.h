#pragma once

#include <map.h>
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

typedef struct
{
    int tile[TILE_HEIGHT][TILE_WIDTH];
    SDL_Texture *grass;
    SDL_Texture *rock;
    SDL_Texture *water;
} Map;

typedef struct
{
    const int FPS;
    const int FRAME_DELAY;
    Uint32 FRAME_START;
    int FRAME_TIME;
} TimeManager;

bool initSDL();
bool initWindow(SDLGame *p_sdl_game, const char *p_title);
void cleanUpSDL(SDLGame *p_sdl_game);
void playGame(SDLGame *sdl_game, GameState game_state, TimeManager time_manager);

SDL_Texture *loadTexture(SDLGame *p_sdl_game, const char *p_path);
void clearRenderer(SDLGame *p_sdl_game);
void renderTexture(SDLGame *p_sdl_game);

Entity initEntity(SDL_Rect p_rect, SDL_Texture *p_texture);
void drawEntity(SDLGame *p_sdl_game, Entity *p_entity);
void updateEntity(Entity *p_entity, SDL_Rect p_rect);

Map loadMap(SDLGame *p_sdl_game);
void drawMap(Map *p_map, SDLGame *p_sdl_game);
