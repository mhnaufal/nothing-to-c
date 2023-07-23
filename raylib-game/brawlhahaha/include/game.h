#pragma once

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <raylib/raylib.h>

#include <util.h>

/********/
/* Data */
/********/
static const int SCREEN_WIDTH = 1440;
static const int SCREEN_HEIGHT = 768;
static const float GRAVITY = 2.5;

static const int SPRITE_WIDTH = 64;
static const int SPRITE_HEIGHT = 64;

static bool is_player1_attack = false;
static bool is_player2_attack = false;

static const int ATTACK_BOX_HEIGHT = 50;
static const int ATTACK_BOX_WIDTH = 150;

enum WINNER_ENUM {
    PLAYER_1 = 1,
    PLAYER_2 = 2
};

static int WINNER = 0;

typedef struct GameManager
{
    EntityManager *entity_manager;
    TextureManager *texture_manager;
    AudioManager *audio_manager;
    UIManager *ui_manager;
} GameManager;

/*************/
/* Functions */
/*************/
GameManager initGameManager(EntityManager em, TextureManager tm, AudioManager am, UIManager um);
void connectEntityManagerToGameManager(GameManager *game_manager, EntityManager *entity_manager, TextureManager *texture_manager);

void gameLoop(GameManager *game_manager);
void updateALL(GameManager *game_manager);
void renderAll(GameManager *game_manager);
void closeALL(GameManager *game_manager);
void renderWinner();

void player1Actions(GameManager *gm);
void player2Actions(GameManager *gm);

void playMusic(AudioManager *am, int index);
void playSound(AudioManager *am, int index);

void player1AttackCollision(GameManager *gm);
void player2AttackCollision(GameManager *gm);
