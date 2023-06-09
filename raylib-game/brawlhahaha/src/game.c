#include <main.h>

void gameLoop(GameManager *game_manager)
{
    time_t begin = time(NULL);
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexturePro(game_manager->entity_manager->m_entities[1].m_texture, (Rectangle){128 * (int)((int)(clock() / 100) % 10), 0, 128, 128}, (Rectangle){SCREEN_WIDTH / 2 - 128 * 2, SCREEN_HEIGHT / 2 - 128 * 2, 128 * 4, 128 * 4}, (Vector2){128 / 2, 128 / 2}, 0, WHITE);
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
