#include <entity.h>

Entity *initEntity(const char *name, CSize *size, ComponentTransform *transform, Rectangle *rectangle, Texture2D *texture)
{
    TraceLog(LOG_INFO, "MANTAPPPP LURR\n");
}

void playerMovement(Entity *entity, bool *facing)
{
    if (IsKeyDown(KEY_A))
    {
        entity->m_transform->position.x -= 5.0f;
        *facing = false;
    }
    if (IsKeyDown(KEY_D))
    {
        entity->m_transform->position.x += 5.0f;
        *facing = true;
    }
    if (IsKeyPressed(KEY_W))
    {
        entity->m_transform->velocity.y = -20.0f;
    }
}

void checkAreaCollision(Entity *entity)
{
    if (entity->m_transform->position.x <= 0)
        entity->m_transform->position.x = 0;
    if (entity->m_transform->position.x + entity->m_size->width >= SCREEN_WIDTH)
        entity->m_transform->position.x = SCREEN_WIDTH - entity->m_size->width;
    if (entity->m_transform->position.y <= 0)
        entity->m_transform->position.y = 0;
}

void checkGravity(Entity *entity)
{
    if (entity->m_transform->position.y + entity->m_size->height + entity->m_transform->velocity.y >= SCREEN_HEIGHT - 125)
    {
        entity->m_transform->velocity.y = 0;
    }
    else
    {
        entity->m_transform->velocity.y += GRAVITY;
    }
}