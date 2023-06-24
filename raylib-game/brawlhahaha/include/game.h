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

static const int SPRITE_WIDHT = 64;
static const int SPRITE_HEIGHT = 64;

typedef struct GameManager
{
    EntityManager *entity_manager;
    TextureManager *texture_manager;
} GameManager;

/*************/
/* Functions */
/*************/
GameManager initGameManager(EntityManager em, TextureManager tm);
void connectEntityManagerToGameManager(GameManager *game_manager, EntityManager *entity_manager, TextureManager *texture_manager);

void gameLoop(GameManager *game_manager);
void updateALL(GameManager *game_manager);
void renderAll(GameManager *game_manager);
void closeALL(GameManager *game_manager);
void freeALL(GameManager *game_manager);

void player1Actions(GameManager *gm);
