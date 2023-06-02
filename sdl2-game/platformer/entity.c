#include <main.h>

/****************/
/*    Entity    */
/****************/
Entity initEntity(SDL_FRect p_rect, SDL_Texture *p_texture, Velocity v)
{
    Entity ent = {&p_rect, p_texture, v};

    return ent;
}

void drawEntity(GameManager *p_game_manager, Entity *p_entity, size_t p_frame)
{
    SDL_Rect src = {32 * (int)((SDL_GetTicks() / 100) % p_frame), 0, 32, 32};
    SDL_Rect dst = {p_entity->property->x, p_entity->property->y, p_entity->property->w, p_entity->property->h};

    SDL_RenderCopy(p_game_manager->renderer, p_entity->texture, &src, &dst);
}

void updateEntity(Entity *p_entity, SDL_FRect p_rect)
{
    if (p_entity->property->y < 0)
    {
        p_entity->property->y = 0;
        p_entity->velocity.y = 0;
    }

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

/****************/
/*    Player    */
/****************/
void playerMove(Entity *p_entity, SDL_Event *p_event)
{
    if (p_event->type == SDL_KEYDOWN)
    {
        switch (p_event->key.keysym.sym)
        {
        case SDLK_d:
            p_entity->property->x += 2.5 + p_entity->velocity.x;
            break;
        case SDLK_a:
            p_entity->property->x -= 2.5 + p_entity->velocity.x;
            break;
        case SDLK_e:
            printf("Interact with object...\n");
            break;
        default:
            break;
        }
    }

    if (p_event->type == SDL_KEYUP)
    {
        switch (p_event->key.keysym.sym)
        {
        case SDLK_SPACE:
            // p_entity->property->y -= 80;
            p_entity->velocity.y -= 5;
            p_entity->property->y += p_entity->velocity.y;
            break;
        }
    }
}
