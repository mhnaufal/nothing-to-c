#include <main.h>
#include <game.h>
#include <util.h>

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Brawlhahaha");

    Texture2D background = LoadTexture("../assets/img/background/moon.png");
    Texture2D tile = LoadTexture("../assets/img/tile/dungeon.png");

    size_t PLAYER_WIDTH = 100;
    size_t PLAYER_HEIGHT = 180;
    ComponentTransform ct1 = {(Vector2){100, 300}, (Vector2){0, 10}};
    Rectangle rt1 = {ct1.position.x, ct1.position.y, PLAYER_WIDTH, PLAYER_HEIGHT};
    CSize cs1 = {PLAYER_WIDTH, PLAYER_HEIGHT};
    Entity e1 = {"", &cs1, &ct1, &rt1, NULL};
    e1.funcs.initEntity = initEntity("Player 1", &cs1, &ct1, &rt1, NULL);

    bool facing_right = true;

    CSize cs2 = {300, 50};
    ComponentTransform ct2 = {e1.m_transform->position, (Vector2){0, 0}};
    Entity e2 = {"", &cs2, &ct2, NULL, NULL};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTextureEx(background, (Vector2){0, 0}, 0.0f, 1.0f, WHITE);

        drawTile(&tile);

        checkAreaCollision(&e1);
        playerMovement(&e1, &facing_right);

        e1.m_transform->position.y += e1.m_transform->velocity.y;
        checkGravity(&e1);

        /* Player Action */
        e2.m_transform->position = e1.m_transform->position;
        if (IsKeyPressed(KEY_J) && facing_right)
        {
            DrawRectangleV(e2.m_transform->position, (Vector2){e2.m_size->width, e2.m_size->height}, BLUE);
        }
        if (IsKeyPressed(KEY_J) && !facing_right)
        {
            DrawRectangleV((Vector2){e2.m_transform->position.x - e2.m_size->width + e1.m_size->width, e2.m_transform->position.y}, (Vector2){e2.m_size->width, e2.m_size->height}, GREEN);
        }

        DrawRectangleV(e1.m_transform->position, (Vector2){e1.m_size->width, e1.m_size->height}, RED);

        DrawText("Brawlhahaha", SCREEN_WIDTH / 2 - 100, 10, 40, BLACK);
        DrawFPS(SCREEN_WIDTH - 100, 10);
        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();

    return 0;
}
