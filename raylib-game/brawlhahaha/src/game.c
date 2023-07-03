#include <game.h>

/***********/
/* Game */
/***********/
GameManager initGameManager(EntityManager em, TextureManager tm, AudioManager am, UIManager um)
{
    GameManager gm;
    gm.entity_manager = &em;
    gm.texture_manager = &tm;
    gm.audio_manager = &am;
    gm.ui_manager = &um;
    return gm;
}

void connectEntityManagerToGameManager(GameManager *game_manager, EntityManager *entity_manager, TextureManager *texture_manager)
{
    game_manager->entity_manager = entity_manager;
    game_manager->texture_manager = texture_manager;
}

void gameLoop(GameManager *game_manager)
{
    playSound(game_manager->audio_manager, 3);

    while (!WindowShouldClose())
    {
        player1Actions(game_manager);
        player2Actions(game_manager);

        BeginDrawing();
            updateALL(game_manager);
            renderAll(game_manager);

                player1AttackCollision(game_manager);
                player2AttackCollision(game_manager);

                DrawRectangleRec(game_manager->ui_manager->m_rect[1], YELLOW);
                DrawRectangleRec(game_manager->ui_manager->m_rect[2], RED);
                DrawRectangleRec(game_manager->ui_manager->m_rect[3], BLUE);

            DrawText("Brawlhahaha", SCREEN_WIDTH / 2 - 100, 10, 40, WHITE);
            DrawFPS(SCREEN_WIDTH - 100, 10);
        EndDrawing();
    }
}

// TODO: refactor movement to seperate function
void updateALL(GameManager *game_manager)
{
    playMusic(game_manager->audio_manager, 1);

    /*
    Turn value into pointer
    https://stackoverflow.com/questions/2094666/pointers-in-c-when-to-use-the-ampersand-and-the-asterisk
    */
    Entity *player1 = &game_manager->entity_manager->m_entities[1];
    Entity *player2 = &game_manager->entity_manager->m_entities[2];

    /* Player 1 Gravity */
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

    /* Player 2 Gravity */
    player2->m_position.y += player2->m_velocity.y;
    if (player2->m_position.y + player2->m_size.y + player2->m_velocity.y >= SCREEN_HEIGHT - SPRITE_HEIGHT)
    {
        player2->m_velocity.y = 0;
    }
    else if (player2->m_position.y < 50)
    {
        player2->m_position.y = 50;
        player2->m_velocity.y = 0;
    }
    else
    {
        player2->m_velocity.y += GRAVITY;
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
    Entity player2 = game_manager->entity_manager->m_entities[2];

    DrawTexturePro(
        player1.m_texture,
        (Rectangle){SPRITE_WIDTH * (int)((int)(clock() / 70) % 10), 0, SPRITE_WIDTH, SPRITE_HEIGHT},
        (Rectangle){player1.m_position.x, player1.m_position.y, SPRITE_WIDTH * 4, SPRITE_HEIGHT * 4},
        (Vector2){SPRITE_WIDTH / 2, SPRITE_HEIGHT / 2},
        0,
        WHITE);

    DrawTexturePro(
        player2.m_texture,
        (Rectangle){SPRITE_WIDTH * (int)((int)(clock() / 70) % 10), 0, -SPRITE_WIDTH, SPRITE_HEIGHT},
        (Rectangle){player2.m_position.x, player2.m_position.y, SPRITE_WIDTH * 4, SPRITE_HEIGHT * 4},
        (Vector2){SPRITE_WIDTH / 2, SPRITE_HEIGHT / 2},
        0,
        WHITE);
}

void closeALL(GameManager *game_manager)
{
    for (int i = 0; i < game_manager->texture_manager->m_total; i++)
    {
        deleteEntity(game_manager->entity_manager, i);
        UnloadTexture(game_manager->texture_manager->m_textures[i]);
    }

    for (int i = 0; i < game_manager->entity_manager->m_total; i++)
    {
        UnloadTexture(game_manager->entity_manager->m_entities[i].m_texture);
    }

    for (int i = 0; i < game_manager->audio_manager->m_total; i++)
    {
        UnloadMusicStream(game_manager->audio_manager->m_music[i]);
        UnloadSound(game_manager->audio_manager->m_sound[i]);
    }

    CloseAudioDevice();
    CloseWindow();
}

/***********/
/* Player */
/***********/
void player1Actions(GameManager *gm)
{
    // update attack box position
    gm->entity_manager->m_entities[3].m_position = gm->entity_manager->m_entities[1].m_position;

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
    else if (IsKeyDown(KEY_THREE)) // prevent attack while moving
    {
        gm->entity_manager->m_entities[1].m_texture = gm->texture_manager->m_textures[5];
        playSound(gm->audio_manager, 2);
        is_player1_attack = true;
    }
    else
    {
        gm->entity_manager->m_entities[1].m_texture = gm->texture_manager->m_textures[1];
    }
}

void player2Actions(GameManager *gm)
{
    // update attack box position
    gm->entity_manager->m_entities[4].m_position = gm->entity_manager->m_entities[2].m_position;

    if (IsKeyPressed(KEY_I))
    {
        gm->entity_manager->m_entities[2].m_velocity.y = -35.0f;
        gm->entity_manager->m_entities[2].m_texture = gm->texture_manager->m_textures[8];
    }
    else if (IsKeyDown(KEY_L))
    {
        gm->entity_manager->m_entities[2].m_position.x += 5.0f;
        gm->entity_manager->m_entities[2].m_texture = gm->texture_manager->m_textures[7];
    }
    else if (IsKeyDown(KEY_J))
    {
        gm->entity_manager->m_entities[2].m_position.x -= 5.0f;
        gm->entity_manager->m_entities[2].m_texture = gm->texture_manager->m_textures[7];
    }
    else if (IsKeyDown(KEY_NINE)) // prevent attack while moving
    {
        gm->entity_manager->m_entities[2].m_texture = gm->texture_manager->m_textures[9];
        playSound(gm->audio_manager, 4);
        is_player2_attack = true;
    }
    else
    {
        gm->entity_manager->m_entities[2].m_texture = gm->texture_manager->m_textures[6];
    }
}

/***********/
/* Audio */
/***********/
void playMusic(AudioManager *am, int index)
{
    UpdateMusicStream(am->m_music[index]);
    PlayMusicStream(am->m_music[index]);
}

void playSound(AudioManager *am, int index)
{
    PlaySound(am->m_sound[index]);
}

/*************/
/* Collision */
/*************/
void player1AttackCollision(GameManager *gm)
{
    Entity attack = gm->entity_manager->m_entities[3];
    Entity player2 = gm->entity_manager->m_entities[2];

    if (attack.m_position.x + attack.m_size.x >= player2.m_position.x
    && attack.m_position.x <= player2.m_position.x + player2.m_size.x
    && attack.m_position.y + attack.m_size.y >= player2.m_position.y
    && attack.m_position.y <= player2.m_position.y + player2.m_size.y
    && is_player1_attack)
    {
        // TODO: reduce health here
        printf("PLAYER 1 ATTACK\n");
    }

    is_player1_attack = false;
}

void player2AttackCollision(GameManager *gm)
{
    Entity attack = gm->entity_manager->m_entities[4];
    Entity player1 = gm->entity_manager->m_entities[1];

    if (attack.m_position.x + attack.m_size.x >= player1.m_position.x
    && attack.m_position.x <= player1.m_position.x + player1.m_size.x
    && attack.m_position.y + attack.m_size.y >= player1.m_position.y
    && attack.m_position.y <= player1.m_position.y + player1.m_size.y
    && is_player2_attack)
    {
        // TODO: reduce health here
        printf("PLAYER 2 ATTACK\n");
    }

    is_player2_attack = false;
}
