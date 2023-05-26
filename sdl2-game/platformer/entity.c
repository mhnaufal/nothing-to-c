#include <entity.h>
#include <main.h>

Entity initEntity(SDL_FRect p_rect, SDL_Texture *p_texture)
{
    Entity ent = {&p_rect, p_texture};

    return ent;
}

void drawEntity(SDLGame *p_sdl_game, Entity *p_entity)
{
    SDL_Rect src = {0, 0, p_entity->frame->w, p_entity->frame->h};
    SDL_Rect dst = {p_entity->frame->x, p_entity->frame->y, p_entity->frame->w, p_entity->frame->h};

    SDL_RenderCopy(p_sdl_game->renderer, p_entity->texture, &src, &dst);
}

void updateEntity(Entity *p_entity, SDL_FRect p_rect)
{
    p_entity->frame->w += p_rect.w;
    p_entity->frame->h += p_rect.h;
    p_entity->frame->x += p_rect.x;
    p_entity->frame->y += p_rect.y + (0.9 * SDL_GetTicks() / 250); // simple enough gravity implementation

    if (p_entity->frame->y >= 400) {
        p_entity->frame->y = 400;
    }

}

void playerMove(Entity *p_entity)
{
}
