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

void playerMovement2(Entity *entity, bool *facing)
{
    if (IsKeyDown(KEY_J))
    {
        entity->m_transform->position.x -= 5.0f;
        *facing = false;
    }
    if (IsKeyDown(KEY_L))
    {
        entity->m_transform->position.x += 5.0f;
        *facing = true;
    }
    if (IsKeyPressed(KEY_I))
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

void playerAction(Entity *player, Entity *attack, bool facing_right)
{
    // if (IsKeyPressed(KEY_THREE) && facing_right)
    // {
        DrawRectangleV(attack->m_transform->position, (Vector2){attack->m_size->width, attack->m_size->height}, DARKPURPLE);
    // }
    // if (IsKeyPressed(KEY_THREE) && !facing_right)
    // {
        DrawRectangleV((Vector2){attack->m_transform->position.x - attack->m_size->width + player->m_size->width, attack->m_transform->position.y}, (Vector2){attack->m_size->width, attack->m_size->height}, GREEN);
    // }
}

void playerAction2(Entity *player, Entity *attack, bool facing_right)
{
    // if (IsKeyPressed(KEY_NINE) && facing_right)
    // {
        DrawRectangleV(attack->m_transform->position, (Vector2){attack->m_size->width, attack->m_size->height}, YELLOW);
    // }
    // if (IsKeyPressed(KEY_NINE) && !facing_right)
    // {
        DrawRectangleV((Vector2){attack->m_transform->position.x - attack->m_size->width + player->m_size->width, attack->m_transform->position.y}, (Vector2){attack->m_size->width, attack->m_size->height}, ORANGE);
    // }
}
