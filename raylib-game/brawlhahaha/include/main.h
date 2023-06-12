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
static const float GRAVITY = 9.5;

static const int SPRITE_WIDHT = 64;
static const int SPRITE_HEIGHT = 64;

enum
{
    MAX_ENTITY = 20
};
enum
{
    MAX_TEXTURE = 20
};

typedef struct Entity
{
    char *m_name;
    Texture2D m_texture;
    Vector2 m_position;
    Vector2 m_size;
    Vector2 m_velocity;
} Entity;

/* EntityManager Table List
[0] : Genesis
[1] : Player 1
*/

typedef struct EntityManager
{
    int total;
    Entity m_entities[MAX_ENTITY];
} EntityManager;

/* TextureManager Table List
[0] : Genesis
[1] : Player 1 Idle
[2] : Player 1 Run
[3] : Background
[4] : Player 1 Attack
*/
typedef struct TextureManager
{
    int total;
    Texture2D m_textures[MAX_TEXTURE];
} TextureManager;

typedef struct Scene
{
    bool paused;
} Scene;

typedef struct GameManager
{
    EntityManager *entity_manager;
    TextureManager *texture_manager;
} GameManager;

Entity initEntity(char *name, TextureManager texture_manager, int texture_id, Vector2 position, Vector2 size);
EntityManager initEntityManager(void);
int addEntity(EntityManager *em, Entity *e);
bool deleteEntity(EntityManager *em, int id);
void player1Movement(GameManager *gm);

void initALL(void);
void closeALL(GameManager *game_manager);
Texture2D loadTexture2D(char *filename, TextureManager *texture_manager);
TextureManager initTextureManager();
int addTexture(TextureManager *texture_manager, Texture2D texture);

void gameLoop(GameManager *game_manager);
GameManager initGameManager(EntityManager em, TextureManager tm);
void connectEntityManagerToGameManager(GameManager *game_manager, EntityManager entity_manager, TextureManager texture_manager);
void renderAll(GameManager *game_manager);

void updateALL(GameManager *game_manager);
