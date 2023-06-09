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

bool addEntity(EntityManager *em, Entity *e)
{
    // TODO: check edge cases
    em->m_entities[em->total + 1] = *e;
    em->total++;

    return true;
}
