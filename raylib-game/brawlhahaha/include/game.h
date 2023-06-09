#pragma once

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <raylib/raylib.h>

typedef struct Scene
{
    bool paused;
} Scene;

typedef struct GameManager
{
    EntityManager *entity_manager;   

} GameManager;

bool initObjects(void);
void gameLoop(GameManager *game_manager);
GameManager initGameManager(void);
void connectEntityManagerToGameManager(GameManager *game_manager, EntityManager entity_manager);
