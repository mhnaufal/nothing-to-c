#include <main.h>

Entity initEntity(char *name, TextureManager texture_manager, int texture_id, Vector2 position, Vector2 size)
{
    Entity e;
    e.m_name = name;
    e.m_texture = texture_manager.m_textures[texture_id];
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
    em->m_entities[id] = (Entity){"", 0, 0, 0};
    em->total--;

    return true;
}

void player1Movement(GameManager *gm)
{
    gm->entity_manager->m_entities[1].m_texture = gm->texture_manager->m_textures[1];

    if (IsKeyDown(KEY_D))
    {
        gm->entity_manager->m_entities[1].m_position.x += 5.0f;
        gm->entity_manager->m_entities[1].m_texture = gm->texture_manager->m_textures[2];
    }
    if (IsKeyDown(KEY_A))
    {
        gm->entity_manager->m_entities[1].m_position.x -= 5.0f;
        gm->entity_manager->m_entities[1].m_texture = gm->texture_manager->m_textures[2];
    }
}
