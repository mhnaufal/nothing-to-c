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
    em.total = 0;
    em.m_entities[em.total] = (Entity){"GENESIS", (Texture2D){0,0,0,0,0}, (Vector2){0,0}, (Vector2){0,0}, (Vector2){0,0}};

    return em;
}

int addEntity(EntityManager *em, Entity *e)
{
    /*
    Can't handle case when there is an empty block between two filledin block.
    To much headcache to be handled without vector, map, or linked list
    */
    em->total++;
    if (em->total >= MAX_ENTITY)
    {
        TraceLog(LOG_ERROR, "Can't add more entity!\n");
        em->total--;
        return 0;
    }
    em->m_entities[em->total] = *e;

    return em->total;
}

bool deleteEntity(EntityManager *em, int id)
{
    em->m_entities[id] = (Entity){"", (Texture2D){0,0,0,0,0}, (Vector2){0,0}, (Vector2){0,0}, (Vector2){0,0}};
    em->total--;

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
    tm.total = 0;

    return tm;
}

int addTexture(TextureManager *texture_manager, Texture2D texture)
{
    texture_manager->total++;
    texture_manager->m_textures[texture_manager->total] = texture;

    return texture_manager->total;
}
