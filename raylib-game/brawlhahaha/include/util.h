#pragma once

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <raylib/raylib.h>
#include <raylib/raymath.h>
#include <raylib/rlgl.h>

static const int SCREEN_WIDTH = 1440;
static const int SCREEN_HEIGHT = 768;
static const float GRAVITY = 2.5;

typedef struct ComponentTransform
{
    Vector2 position;
    Vector2 velocity;
} ComponentTransform;

typedef struct CSize
{
    float width;
    float height;
} CSize;
