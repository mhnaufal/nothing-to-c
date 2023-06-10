#include <main.h>

void gameLoop(GameManager *game_manager)
{
    time_t begin = time(NULL);
    while (!WindowShouldClose())
    {
        BeginDrawing();
            renderAll(game_manager);
        EndDrawing();
    }
}

GameManager initGameManager(void)
{
    GameManager gm;
    return gm;
}

void connectEntityManagerToGameManager(GameManager *game_manager, EntityManager entity_manager)
{
    game_manager->entity_manager = &entity_manager;
}

void renderAll(GameManager *game_manager)
{
    ClearBackground(RAYWHITE);

    DrawTexturePro(game_manager->entity_manager->m_entities[1].m_texture, (Rectangle){SPRITE_WIDHT * (int)((int)(clock() / 100) % 10), 0, SPRITE_WIDHT, SPRITE_HEIGHT}, (Rectangle){SCREEN_WIDTH / 2 - SPRITE_WIDHT * 2, SCREEN_HEIGHT / 2 - SPRITE_HEIGHT * 2, SPRITE_WIDHT * 4, SPRITE_HEIGHT * 4}, (Vector2){SPRITE_WIDHT / 2, SPRITE_HEIGHT / 2}, 0, WHITE);
}
