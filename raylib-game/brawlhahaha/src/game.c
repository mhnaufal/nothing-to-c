#include <game.h>

/***********/
/* Game */
/***********/
GameManager initGameManager(EntityManager em, TextureManager tm)
{
    GameManager gm;
    gm.entity_manager = &em;
    gm.texture_manager = &tm;
    return gm;
}

void connectEntityManagerToGameManager(GameManager *game_manager, EntityManager *entity_manager, TextureManager *texture_manager)
{
    game_manager->entity_manager = entity_manager;
    game_manager->texture_manager = texture_manager;
}

void gameLoop(GameManager *game_manager)
{
    while (!WindowShouldClose())
    {
        player1Actions(game_manager);

        BeginDrawing();
        updateALL(game_manager);
        renderAll(game_manager);
        EndDrawing();
    }
}

void updateALL(GameManager *game_manager)
{
    /*
    Turn value into pointer
    https://stackoverflow.com/questions/2094666/pointers-in-c-when-to-use-the-ampersand-and-the-asterisk
    */
    Entity *player1 = &game_manager->entity_manager->m_entities[1];

    /* Player Gravity */
    player1->m_position.y += player1->m_velocity.y;
    if (player1->m_position.y + player1->m_size.y + player1->m_velocity.y >= SCREEN_HEIGHT - SPRITE_HEIGHT)
    {
        player1->m_velocity.y = 0;
    }
    else if (player1->m_position.y < 50)
    {
        player1->m_position.y = 50;
        player1->m_velocity.y = 0;
    }
    else
    {
        player1->m_velocity.y += GRAVITY;
    }
}

void renderAll(GameManager *game_manager)
{
    ClearBackground(RAYWHITE);

    DrawTextureEx(game_manager->texture_manager->m_textures[3], (Vector2){
                                                                    0,
                                                                    0,
                                                                },
                  0.0f, 1.0f, WHITE);

    Entity player1 = game_manager->entity_manager->m_entities[1];

    DrawTexturePro(
        player1.m_texture,
        (Rectangle){SPRITE_WIDHT * (int)((int)(clock() / 150) % 10), 0, SPRITE_WIDHT, SPRITE_HEIGHT},
        (Rectangle){player1.m_position.x, player1.m_position.y, SPRITE_WIDHT * 4, SPRITE_HEIGHT * 4},
        (Vector2){SPRITE_WIDHT / 2, SPRITE_HEIGHT / 2},
        0,
        WHITE);
}

void closeALL(GameManager *game_manager)
{
    for (int i = 0; i < game_manager->entity_manager->total; i++)
    {
        UnloadTexture(game_manager->entity_manager->m_entities[i].m_texture);
    }

    CloseAudioDevice();
    CloseWindow();
}

void freeALL(GameManager *game_manager)
{
    for (int i = 0; i < game_manager->texture_manager->total; i++)
    {
        deleteEntity(game_manager->entity_manager, i);
        UnloadTexture(game_manager->texture_manager->m_textures[i]);
    }
}

/***********/
/* Player */
/***********/
void player1Actions(GameManager *gm)
{
    if (IsKeyPressed(KEY_W))
    {
        gm->entity_manager->m_entities[1].m_velocity.y = -35.0f;
        gm->entity_manager->m_entities[1].m_texture = gm->texture_manager->m_textures[4];
    }
    else if (IsKeyDown(KEY_D))
    {
        gm->entity_manager->m_entities[1].m_position.x += 5.0f;
        gm->entity_manager->m_entities[1].m_texture = gm->texture_manager->m_textures[2];
    }
    else if (IsKeyDown(KEY_A))
    {
        gm->entity_manager->m_entities[1].m_position.x -= 5.0f;
        gm->entity_manager->m_entities[1].m_texture = gm->texture_manager->m_textures[2];
    }
    else if (IsKeyDown(KEY_V)) // prevent attack while moving
    {
        gm->entity_manager->m_entities[1].m_texture = gm->texture_manager->m_textures[5];
    }
    else
    {
        gm->entity_manager->m_entities[1].m_texture = gm->texture_manager->m_textures[1];
    }
}
