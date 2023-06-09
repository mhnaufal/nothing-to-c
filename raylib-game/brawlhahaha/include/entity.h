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

#include <util.h>

typedef struct Entity
{
    char *m_name;
    CSize *m_size;
    ComponentTransform *m_transform;
    Rectangle *m_shape;
    Texture2D *m_texture;

    struct funcs
    {
        struct Entity *(*initEntity)(const char *name, CSize *size, ComponentTransform *transform, Rectangle *rectangle, Texture2D *texture);
    } funcs;
} Entity;

typedef struct EntityMap
{
    char *name;
    Entity entity;
} EntityMap;

typedef struct EntityManager
{
    size_t total;
    EntityMap entities[];
} EntityManager;

Entity *initEntity(const char *name, CSize *size, ComponentTransform *transform, Rectangle *rectangle, Texture2D *texture);

void playerMovement(Entity *entity, bool *facing);
void playerMovement2(Entity *entity, bool *facing);
void checkAreaCollision(Entity *entity);
void checkGravity(Entity *entity);
void playerAction(Entity *player, Entity *attack, bool facing_right, bool *is_attacking);
void playerAction2(Entity *player, Entity *attack, bool facing_right);
