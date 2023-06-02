#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <game.h>

/*****************/
/* Initial Setup */
/*****************/
bool initALL(void);
bool initWindow(GameManager *p_sdl_game, const char *p_title);
void cleanUpSDL(GameManager *p_sdl_game);

/************/
/* Renderer */
/************/
SDL_Texture *loadTexture(GameManager *p_sdl_game, const char *p_path);
void clearRenderer(GameManager *p_sdl_game);
void renderTexture(GameManager *p_sdl_game);

/********/
/* Font */
/********/
TTF_Font *initFont(const char *p_font, int p_size);
void drawText(TTF_Font *p_font, GameManager *p_sdl_game, const char *p_text, int p_x, int p_y, int p_r, int p_g, int p_b, int p_a);

/*********/
/* Audio */
/*********/
Mix_Chunk *loadSound(const char *p_audio_file);
Mix_Music *loadMusic(const char *p_audio_file);
void playSound(Mix_Chunk *p_sound, int p_channel, int p_loop);
void playMusic(Mix_Music *p_music, int p_loop);
void clearSound(Mix_Chunk *p_sound);
void clearMusic(Mix_Music *p_music);
