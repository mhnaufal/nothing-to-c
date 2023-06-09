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
    Entity e1 = {"", &cs1, &ct1, &rt1, NULL, {NULL}};
    // e1.funcs.initEntity = initEntity("Player 1", &cs1, &ct1, &rt1, NULL);
    // em1.name = "Player 1";
    // em1.entity = e1;

    bool facing_right = true;

    CSize cs2 = {300, 50};
    ComponentTransform ct2 = {e1.m_transform->position, (Vector2){0, 0}};
    Entity e2 = {"", &cs2, &ct2, NULL, NULL, {NULL}};
    // em2.name = "Attack Box";
    // em2.entity = e2;

    // Player 2
    ComponentTransform ct3 = {(Vector2){1300, 300}, (Vector2){0, 10}};
    Rectangle rt3 = {ct3.position.x, ct3.position.y, PLAYER_WIDTH, PLAYER_HEIGHT};
    CSize cs3 = {PLAYER_WIDTH, PLAYER_HEIGHT};
    Entity e3 = {"", &cs3, &ct3, &rt3, NULL, {NULL}};
    bool facing_right_3 = false;
    CSize cs4 = {300, 50};
    ComponentTransform ct4 = {e3.m_transform->position, (Vector2){0, 0}};
    Entity e4 = {"", &cs4, &ct4, NULL, NULL, {NULL}};

    /*
        EntityManager *emg1 = malloc(sizeof(EntityManager) + 100 * sizeof(EntityMap));
        emg1->total = 2;
        emg1->entities[0] = em1;
        emg1->entities[1] = em2;
    */

    /* TODO: refactor health system */
    Rectangle base_health1 = {0, 0, SCREEN_WIDTH / 2, 50};
    float rem1 = 0;
    Rectangle health1 = {rem1 * 100, 0, SCREEN_WIDTH / 2 - 0, 50};

    Rectangle base_health2 = {SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, 50};
    float rem2 = 0;
    Rectangle health2 = {SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, 50};

    SetTargetFPS(60);

    PlaySound(sound_start);
    while (!WindowShouldClose())
    {
        /* TODO: health reducing system */
        rem1++;
        health1.x = rem1;
        health1.width = SCREEN_WIDTH / 2 - rem1;

        rem2++;
        health2.width -= rem2 / 100;

        /* Audio */
        SetMusicVolume(music_bg, 0.2);
        UpdateMusicStream(music_bg);
        PlayMusicStream(music_bg);

        /* Collision */
        checkAreaCollision(&e1);
        checkAreaCollision(&e3);

        /* Movement */
        playerMovement(&e1, &facing_right);
        playerMovement2(&e3, &facing_right_3);

        /* Gravity */
        e1.m_transform->position.y += e1.m_transform->velocity.y;
        checkGravity(&e1);

        e3.m_transform->position.y += e3.m_transform->velocity.y;
        checkGravity(&e3);

        /* Player Action */
        e2.m_transform->position = e1.m_transform->position;
        e4.m_transform->position = e3.m_transform->position;

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTextureEx(background, (Vector2){0, 0}, 0.0f, 1.0f, WHITE);

            drawTile(&tile);

            /* Draw Player */
            DrawRectangleV(e1.m_transform->position, (Vector2){e1.m_size->width, e1.m_size->height}, RED);
            DrawRectangleV(e3.m_transform->position, (Vector2){e3.m_size->width, e3.m_size->height}, BLUE);

            /* Player 1 Action */
            playerAction(&e1, &e2 , facing_right);

            /* Player 2 Action */
            playerAction2(&e3, &e4,  facing_right_3);

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
