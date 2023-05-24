#include <main.h>

int main(int argc, char *argv[])
{
    initSDL();

    GameState game_state = {true, false, false, false, false, false};
    SDLGame sdl_game = {NULL, NULL};

    initWindow(&sdl_game, "Catty The Cat");

    SDL_Rect entity_size = {0, WINDOW_HEIGHT / 2 - PIXEL_HEIGHT, PIXEL_WIDTH, PIXEL_HEIGHT};
    SDL_Rect new_size = {1, -1, 1, 1};

    SDL_Texture *texture1 = loadTexture(&sdl_game, "./res/gfx/cat1.png");
    Entity cat1 = initEntity(entity_size, texture1);

    SDL_Event event;

    while (!game_state.Exit)
    {
        FRAME_START = SDL_GetTicks();

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                game_state.Exit = true;
            }
        }

        updateEntity(&cat1, new_size);

        drawEntity(&sdl_game, &cat1);

        FRAME_TIME = SDL_GetTicks() - FRAME_START;

        if (FRAME_DELAY >= FRAME_TIME)
            SDL_Delay(FRAME_DELAY - FRAME_TIME);

        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "[FPS] %d - %d\n", FRAME_TIME, FRAME_DELAY);
    }

    cleanUpSDL(&sdl_game);
    SDL_Quit();

    return 0;
}

bool initSDL()
{
    bool is_success = true;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_CRITICAL, "[Failed to init SDL2: %s]\n", SDL_GetError());
        is_success = false;
    }

    if (!(IMG_INIT_PNG))
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to init SDL2 Image for PNG: %s]\n", SDL_GetError());
        is_success = false;
    }

    return is_success;
}

bool initWindow(SDLGame *p_sdl_game, const char *p_title)
{
    bool is_success = true;

    p_sdl_game->window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (p_sdl_game->window == NULL)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_CRITICAL, "[Failed to init SDL2 window: %s]\n", SDL_GetError());
        is_success = false;
    }

    p_sdl_game->renderer = SDL_CreateRenderer(p_sdl_game->window, -1, SDL_RENDERER_ACCELERATED);
    if (p_sdl_game->renderer == NULL)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to init SDL2 renderer: %s]\n", SDL_GetError());
        is_success = false;
    }

    return is_success;
}

void cleanUpSDL(SDLGame *p_sdl_game)
{
    SDL_DestroyRenderer(p_sdl_game->renderer);
    SDL_DestroyWindow(p_sdl_game->window);
}

SDL_Texture *loadTexture(SDLGame *p_sdl_game, const char *p_path)
{
    SDL_Texture *texture = IMG_LoadTexture(p_sdl_game->renderer, p_path);
    if (texture == NULL)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to load texture: %s]\n", SDL_GetError());
    }

    return texture;
}

Entity initEntity(SDL_Rect p_rect, SDL_Texture *p_texture)
{
    Entity ent = {&p_rect, p_texture};

    return ent;
}

void drawEntity(SDLGame *p_sdl_game, Entity *p_entity)
{
    SDL_RenderClear(p_sdl_game->renderer);

    SDL_Rect src = {0, 0, p_entity->frame->w, p_entity->frame->h};
    SDL_Rect dst = {p_entity->frame->x, p_entity->frame->y, p_entity->frame->w, p_entity->frame->h};

    SDL_RenderCopy(p_sdl_game->renderer, p_entity->texture, &src, &dst);
    SDL_RenderPresent(p_sdl_game->renderer);
}

void updateEntity(Entity *p_entity, SDL_Rect p_rect)
{
    p_entity->frame->w += p_rect.w;
    p_entity->frame->h += p_rect.h;
    p_entity->frame->x += p_rect.x;
    p_entity->frame->y += p_rect.y;
}
