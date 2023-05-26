#pragma once

#include <map.h>
#include <game.h>
#include <entity.h>

bool initSDL();
bool initWindow(SDLGame *p_sdl_game, const char *p_title);
void cleanUpSDL(SDLGame *p_sdl_game);
void playGame(SDLGame *sdl_game, GameState game_state, TimeManager time_manager);

SDL_Texture *loadTexture(SDLGame *p_sdl_game, const char *p_path);
void clearRenderer(SDLGame *p_sdl_game);
void renderTexture(SDLGame *p_sdl_game);
