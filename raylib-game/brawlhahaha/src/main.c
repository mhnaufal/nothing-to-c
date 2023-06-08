#include <main.h>
#include <game.h>
#include <util.h>

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Brawlhahaha");
    InitAudioDevice();

    Texture2D background = LoadTexture("../assets/img/background/moon.png");
    Texture2D tile = LoadTexture("../assets/img/tile/dungeon.png");
    Music music_bg = LoadMusicStream("../assets/audio/war.mp3");
    Sound sound_start = LoadSound("../assets/audio/ready-fight.mp3");

    EntityMap em1;
    EntityMap em2;

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

    /*
        EntityManager *emg1 = malloc(sizeof(EntityManager) + 100 * sizeof(EntityMap));
        emg1->total = 2;
        emg1->entities[0] = em1;
        emg1->entities[1] = em2;
    */

    SetTargetFPS(60);

    PlaySound(sound_start);
    while (!WindowShouldClose())
    {
        /* Audio */
        SetMusicVolume(music_bg, 0.2);
        UpdateMusicStream(music_bg);
        PlayMusicStream(music_bg);

        /* Collision */
        checkAreaCollision(&e1);

        /* Movement */
        playerMovement(&e1, &facing_right);

        /* Gravity */
        e1.m_transform->position.y += e1.m_transform->velocity.y;
        checkGravity(&e1);

        /* Player Action */
        e2.m_transform->position = e1.m_transform->position;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTextureEx(background, (Vector2){0, 0}, 0.0f, 1.0f, WHITE);

        drawTile(&tile);
        DrawRectangleV(e1.m_transform->position, (Vector2){e1.m_size->width, e1.m_size->height}, RED);

        if (IsKeyPressed(KEY_J) && facing_right)
        {
            DrawRectangleV(e2.m_transform->position, (Vector2){e2.m_size->width, e2.m_size->height}, BLUE);
        }
        if (IsKeyPressed(KEY_J) && !facing_right)
        {
            DrawRectangleV((Vector2){e2.m_transform->position.x - e2.m_size->width + e1.m_size->width, e2.m_transform->position.y}, (Vector2){e2.m_size->width, e2.m_size->height}, GREEN);
        }

        DrawText("Brawlhahaha", SCREEN_WIDTH / 2 - 100, 10, 40, BLACK);
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
