#include <entity.h>
#include <main.h>

Entity initEntity(SDL_FRect p_rect, SDL_Texture *p_texture, Velocity v)
{
    Entity ent = {&p_rect, p_texture, v};

    return ent;
}

void drawEntity(SDLGame *p_sdl_game, Entity *p_entity)
{
    SDL_Rect src = {0, 0, p_entity->property->w, p_entity->property->h};
    SDL_Rect dst = {p_entity->property->x, p_entity->property->y, p_entity->property->w, p_entity->property->h};

    SDL_RenderCopy(p_sdl_game->renderer, p_entity->texture, &src, &dst);
}

void updateEntity(Entity *p_entity, SDL_FRect p_rect, Velocity p_velocity)
{
    if (p_entity->property->y + p_entity->property->h >= WINDOW_HEIGHT - (PIXEL_HEIGHT * 1.5))
        p_entity->velocity.y = 0;
    else
    {
        p_entity->velocity.y += GRAVITY;
        p_entity->property->x += p_entity->velocity.x;
        p_entity->property->y += p_entity->velocity.y;
    }

    p_entity->property->w += p_rect.w;
    p_entity->property->h += p_rect.h;
}

void playerMove(Entity *p_entity)
{
}
