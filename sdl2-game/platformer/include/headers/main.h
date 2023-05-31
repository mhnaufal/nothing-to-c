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

void drawText(SDLGame *p_sdl_game, const char *p_text, int p_x, int p_y, int p_r, int p_g, int p_b, int p_size);
SDL_AudioDeviceID loadAudio(const char *p_audio_file);
void playAudio(SDL_AudioDeviceID p_audio_id);
