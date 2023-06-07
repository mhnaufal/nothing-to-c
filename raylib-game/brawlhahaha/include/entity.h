#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <raylib/raylib.h>
#include <raylib/raymath.h>
#include <raylib/rlgl.h>

typedef struct ComponentTransform
{
    Vector2 position;
    Vector2 velocity;
} ComponentTransform;

typedef struct Entity
{
    char *m_name;
    ComponentTransform *m_transform;
    Rectangle *m_shape;
    Texture2D *m_texture;

    struct funcs
    {
        struct Entity *(*init_entity)(const char *name, ComponentTransform *transform, Rectangle *rectangle, Texture2D *texture);
    } funcs;
} Entity;

Entity *init_entity(const char *name, ComponentTransform *transform, Rectangle *rectangle, Texture2D *texture);
