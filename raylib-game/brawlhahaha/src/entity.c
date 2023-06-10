#include <main.h>

Entity initEntity(char *name, char *texture_file, Vector2 position, Vector2 size)
{
    Texture2D t = loadTexture2D(texture_file);

    Entity e;
    e.m_name = name;
    e.m_texture = t;
    e.m_position = position;
    e.m_size = size;

    return e;
}

EntityManager initEntityManager(void)
{
    EntityManager em;
    em.total = 0;
    em.m_entities[em.total] = (Entity){"GENESIS", 0, 0, 0};

    return em;
}

int addEntity(EntityManager *em, Entity *e)
{
    /*
    Can't handle case when there is an empty block between two filledin block.
    To much headcache to be handled without vector or map
    */
    if (em->total >= MAX_ENTITY)
    {
        TraceLog(LOG_ERROR, "Can't add more entity!\n");
        return 0;
    }
    em->m_entities[em->total + 1] = *e;
    em->total++;

    return em->total;
}

bool deleteEntity(EntityManager *em, int id)
{
    em->m_entities[id] = (Entity){"", 0, 0, 0};
    em->total--;

    return true;
}
