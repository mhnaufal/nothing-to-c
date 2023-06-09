#include <main.h>
#include <game.h>
#include <util.h>

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Brawlhahaha");
    InitAudioDevice();

    /* TODO: refactor texture laoding */
    Texture2D background = LoadTexture("../assets/img/background/moon.png");
    Texture2D tile = LoadTexture("../assets/img/tile/dungeon.png");
    Music music_bg = LoadMusicStream("../assets/audio/war.mp3");
    Sound sound_start = LoadSound("../assets/audio/ready-fight.mp3");

    /* TODO: refactor entity initialization */
    EntityMap em1;
    EntityMap em2;

    // Player 1
    size_t PLAYER_WIDTH = 100;
    size_t PLAYER_HEIGHT = 180;
    ComponentTransform ct1 = {(Vector2){100, 300}, (Vector2){0, 10}};
    Rectangle rt1 = {ct1.position.x, ct1.position.y, PLAYER_WIDTH, PLAYER_HEIGHT};
    CSize cs1 = {PLAYER_WIDTH, PLAYER_HEIGHT};
    Entity player1 = {"", &cs1, &ct1, &rt1, NULL, {NULL}};
    // player1.funcs.initEntity = initEntity("Player 1", &cs1, &ct1, &rt1, NULL);
    // em1.name = "Player 1";
    // em1.entity = player1;
    bool facing_right1 = true;
    CSize cs2 = {300, 50};
    ComponentTransform ct2 = {player1.m_transform->position, (Vector2){0, 0}};
    Entity attack1 = {"", &cs2, &ct2, NULL, NULL, {NULL}};
    bool is_attacking1 = false;

    // Player 2
    ComponentTransform ct3 = {(Vector2){1300, 300}, (Vector2){0, 10}};
    Rectangle rt3 = {ct3.position.x, ct3.position.y, PLAYER_WIDTH, PLAYER_HEIGHT};
    CSize cs3 = {PLAYER_WIDTH, PLAYER_HEIGHT};
    Entity player2 = {"", &cs3, &ct3, &rt3, NULL, {NULL}};
    bool facing_right2 = false;
    CSize cs4 = {300, 50};
    ComponentTransform ct4 = {player2.m_transform->position, (Vector2){0, 0}};
    Entity attack2 = {"", &cs4, &ct4, NULL, NULL, {NULL}};
    bool is_attacking2 = false;

    /*
        EntityManager *emg1 = malloc(sizeof(EntityManager) + 100 * sizeof(EntityMap));
        emg1->total = 2;
        emg1->entities[0] = em1;
        emg1->entities[1] = em2;
    */

    /* TODO: refactor health system */
    Rectangle base_health1 = {0, 0, SCREEN_WIDTH / 2, 50};
    float remaining1 = 0;
    Rectangle health1 = {remaining1 * 100, 0, SCREEN_WIDTH / 2 - 0, 50};

    Rectangle base_health2 = {SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, 50};
    float remaining2 = 0;
    Rectangle health2 = {SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, 50};

    SetTargetFPS(60);

    PlaySound(sound_start);
    while (!WindowShouldClose())
    {
        /* TODO: health reducing system */
        remaining1++;
        health1.x = remaining1;
        health1.width = SCREEN_WIDTH / 2 - remaining1;

        remaining2++;
        health2.width -= remaining2 / 100;

        /* Audio */
        SetMusicVolume(music_bg, 0.2);
        UpdateMusicStream(music_bg);
        PlayMusicStream(music_bg);

        /* Collision */
        checkAreaCollision(&player1);
        checkAreaCollision(&player2);

        /* Movement */
        playerMovement(&player1, &facing_right1);
        playerMovement2(&player2, &facing_right2);

        /* Gravity */
        player1.m_transform->position.y += player1.m_transform->velocity.y;
        checkGravity(&player1);

        player2.m_transform->position.y += player2.m_transform->velocity.y;
        checkGravity(&player2);

        /* Player Action */
        attack1.m_transform->position = player1.m_transform->position;
        attack2.m_transform->position = player2.m_transform->position;

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTextureEx(background, (Vector2){0, 0}, 0.0f, 1.0f, WHITE);

            drawTile(&tile);

            /* Draw Player */
            DrawRectangleV(player1.m_transform->position, (Vector2){player1.m_size->width, player1.m_size->height}, RED);
            DrawRectangleV(player2.m_transform->position, (Vector2){player2.m_size->width, player2.m_size->height}, BLUE);

            /* Player 1 Action */
            playerAction(&player1, &attack1 , facing_right1, &is_attacking1);

            /* Player 2 Action */
            playerAction2(&player2, &attack2,  facing_right2);

            /* Player 1 Attack Collision */
            if (attack1.m_transform->position.x + attack1.m_size->width >= player2.m_transform->position.x
            && attack1.m_transform->position.x <= player2.m_transform->position.x + player2.m_size->width
            && attack1.m_transform->position.y + attack1.m_size->height >= player2.m_transform->position.y
            && attack1.m_transform->position.y <= player2.m_transform->position.y + player2.m_size->height
            && is_attacking1)
            {
                printf("PLAYER 1 ATTACK\n");
            }
            is_attacking1 = false;
            is_attacking2 = false;

            /* Draw Health Bar */
            DrawRectangleRec(base_health1, YELLOW);
            DrawRectangleRec(health1, RED);
            DrawRectangleRec(base_health2, GREEN);
            DrawRectangleRec(health2, BLUE);
            DrawText("Brawlhahaha", SCREEN_WIDTH / 2 - 100, 10, 40, WHITE);
            DrawFPS(SCREEN_WIDTH - 100, 10);
        EndDrawing();
    }

    // free(emg1);

    UnloadMusicStream(music_bg);
    UnloadSound(sound_start);
    UnloadTexture(background);
    UnloadTexture(tile);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
