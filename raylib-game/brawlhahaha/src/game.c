#include <main.h>

void gameLoop(GameManager *game_manager)
{
    time_t begin = time(NULL);
    while (!WindowShouldClose())
    {
        player1Movement(game_manager);

        BeginDrawing();
            renderAll(game_manager);
        EndDrawing();
    }
}

GameManager initGameManager(EntityManager em, TextureManager tm)
{
    GameManager gm;
    gm.entity_manager = &em;
    gm.texture_manager = &tm;
    return gm;
}

void connectEntityManagerToGameManager(GameManager *game_manager, EntityManager entity_manager, TextureManager texture_manager)
{
    game_manager->entity_manager = &entity_manager;
    game_manager->texture_manager = &texture_manager;
}

void renderAll(GameManager *game_manager)
{
    ClearBackground(RAYWHITE);

    Entity player1 = game_manager->entity_manager->m_entities[1];

    DrawTexturePro(
        player1.m_texture,
        (Rectangle){SPRITE_WIDHT * (int)((int)(clock() / 100) % 10), 0, SPRITE_WIDHT, SPRITE_HEIGHT},
        (Rectangle){player1.m_position.x, player1.m_position.y, SPRITE_WIDHT * 4, SPRITE_HEIGHT * 4},
        (Vector2){SPRITE_WIDHT / 2, SPRITE_HEIGHT / 2},
        0,
        WHITE);
}
