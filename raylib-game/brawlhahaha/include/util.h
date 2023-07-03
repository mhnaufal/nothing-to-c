#pragma once

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <raylib/raylib.h>

/********/
/* Data */
/********/
enum
{
    MAX_ENTITY = 20
};
enum
{
    MAX_TEXTURE = 20
};
enum
{
    MAX_AUDIO = 20
};
enum
{
    MAX_UI = 20
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
[2] : Player 2
[3] : Player 1 Attack
[4] : Player 2 Attack
*/

typedef struct EntityManager
{
    int m_total;
    Entity m_entities[MAX_ENTITY];
} EntityManager;

/* TextureManager Table List
[0] : Genesis
[1] : Player 1 Idle
[2] : Player 1 Run
[3] : Background
[4] : Player 1 Jump
[5] : Player 1 Attack
[6] : Player 2 Idle
[7] : Player 2 Run
[8] : Player 2 Jump
[9] : Player 2 Attack
*/
typedef struct TextureManager
{
    int m_total;
    Texture2D m_textures[MAX_TEXTURE];
} TextureManager;

typedef struct AudioManager
{
    int m_total;
    Music m_music[MAX_AUDIO];
    Sound m_sound[MAX_AUDIO];
} AudioManager;

typedef struct UIManager
{
    int m_total;
    Rectangle m_rect[MAX_UI];
} UIManager;

/*************/
/* Functions */
/*************/
void initALL(void);

Entity initEntity(char *name, TextureManager texture_manager, int texture_id, Vector2 position, Vector2 size);
EntityManager initEntityManager(void);
int addEntity(EntityManager *em, Entity *e);
bool deleteEntity(EntityManager *em, int id);

Texture2D loadTexture2D(char *filename);
TextureManager initTextureManager();
int addTexture(TextureManager *texture_manager, Texture2D texture);

AudioManager initAudioManager();
int addMusic(AudioManager *audio_manager, Music music);
int addSound(AudioManager *audio_manager, Sound sound);

UIManager initUIManager();
int addUI(UIManager *ui_manager, Rectangle rect);
