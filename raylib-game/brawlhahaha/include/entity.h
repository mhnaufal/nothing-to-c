#pragma once

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <raylib/raylib.h>

static const int MAX_ENTITY = 20;

typedef struct Entity
{
    char *m_name;
    Texture2D m_texture;
    Vector2 m_position;
    Vector2 m_size;
} Entity;

typedef struct EntityManager
{
    int total;
    Entity m_entities[MAX_ENTITY];
} EntityManager;

Entity initEntity(char *name, char *texture_file, Vector2 position, Vector2 size);
EntityManager initEntityManager(void);
int addEntity(EntityManager *em, Entity *e);
bool deleteEntity(EntityManager *em, int id);
