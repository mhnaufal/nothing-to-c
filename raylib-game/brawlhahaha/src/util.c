#include <main.h>

void initALL(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    InitAudioDevice();
    SetTargetFPS(60);
}

/**********/
/* Entity */
/**********/
Entity initEntity(char *name, TextureManager texture_manager, int texture_id, Vector2 position, Vector2 size)
{
    Entity e;
    e.m_name = name;
    e.m_texture = texture_manager.m_textures[texture_id];
    e.m_position = position;
    e.m_size = size;
    e.m_velocity = (Vector2){0, 0};

    return e;
}

EntityManager initEntityManager(void)
{
    EntityManager em;
    em.m_total = 0;
    em.m_entities[em.m_total] = (Entity){"GENESIS", (Texture2D){0, 0, 0, 0, 0}, (Vector2){0, 0}, (Vector2){0, 0}, (Vector2){0, 0}};

    return em;
}

int addEntity(EntityManager *em, Entity *e)
{
    /*
    Can't handle case when there is an empty block between two filled in block.
    Too much headcache to be handled without vector, map, or linked list
    */
    em->m_total++;
    if (em->m_total >= MAX_ENTITY)
    {
        TraceLog(LOG_ERROR, "Can't add more entity!\n");
        em->m_total--;
        return 0;
    }
    em->m_entities[em->m_total] = *e;

    return em->m_total;
}

bool deleteEntity(EntityManager *em, int id)
{
    em->m_entities[id] = (Entity){"", (Texture2D){0, 0, 0, 0, 0}, (Vector2){0, 0}, (Vector2){0, 0}, (Vector2){0, 0}};
    em->m_total--;

    return true;
}

/***********/
/* Texture */
/***********/
Texture2D loadTexture2D(char *filename)
{
    Texture2D t = LoadTexture(filename);

    return t;
}

TextureManager initTextureManager()
{
    TextureManager tm;
    tm.m_total = 0;

    return tm;
}

int addTexture(TextureManager *texture_manager, Texture2D texture)
{
    texture_manager->m_total++;
    texture_manager->m_textures[texture_manager->m_total] = texture;

    return texture_manager->m_total;
}

/***********/
/* Audio */
/***********/
AudioManager initAudioManager(void)
{
    AudioManager am;
    am.m_total = 0;

    return am;
}

int addMusic(AudioManager *audio_manager, Music music)
{
    audio_manager->m_total++;
    audio_manager->m_music[audio_manager->m_total] = music;

    return audio_manager->m_total;
}

int addSound(AudioManager *audio_manager, Sound sound)
{
    audio_manager->m_total++;
    audio_manager->m_sound[audio_manager->m_total] = sound;

    return audio_manager->m_total;
}


/***********/
/* UI */
/***********/
UIManager initUIManager()
{
    UIManager um;
    um.m_total = 0;

    return um;
}

int addUI(UIManager *ui_manager, Rectangle rect)
{
    ui_manager->m_total++;
    ui_manager->m_rect[ui_manager->m_total] = rect;

    return ui_manager->m_total;
}
