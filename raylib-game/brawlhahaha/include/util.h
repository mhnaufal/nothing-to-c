#pragma once

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <raylib/raylib.h>

static const char *GAME_NAME = "Brawlhahaha";
static const int SCREEN_WIDTH = 1440;
static const int SCREEN_HEIGHT = 768;
static const float GRAVITY = 2.5;

static const int SPRITE_WIDHT = 64;
static const int SPRITE_HEIGHT = 64;

void initALL(void);
void closeALL(GameManager *game_manager);
Texture2D loadTexture2D(char *filename);
