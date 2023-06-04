#include <main.h>

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
    const int SCREEN_WIDTH = 1440;
    const int SCREEN_HEIGHT = 768;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Brawlhahaha");

    Texture2D background = LoadTexture("../assets/img/background/moon.png");
    Texture2D tile = LoadTexture("../assets/img/tile/dungeon.png");
    Font font = LoadFont("../assets/font/opensans.ttf");

    Vector2 player_position = {(float)100, (float)100};
    float player_velocity = 10;
    float gravity = 0.3;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextureEx(background, (Vector2){0, 0}, 0.0f, 1.0f, WHITE);

        for (int i = -20; i <= SCREEN_WIDTH; i += 48)
        {
            DrawTextureRec(tile, (Rectangle){0, 0, 64, 64}, (Vector2){i, SCREEN_HEIGHT - 140}, WHITE);
            DrawTextureRec(tile, (Rectangle){0, 0, 64, 64}, (Vector2){i, SCREEN_HEIGHT - 100}, WHITE);
            DrawTextureRec(tile, (Rectangle){0, 0, 64, 64}, (Vector2){i, SCREEN_HEIGHT - 60}, WHITE);
        }

        DrawRectangleV(player_position, (Vector2){100, 180}, RED);
        player_position.y += player_velocity;
        if (player_position.y + 180 + player_velocity >= SCREEN_HEIGHT - 125)
        {
            player_velocity = 0;
        }
        else
        {
            player_velocity += gravity;
        }

        DrawText("Brawlhahaha", SCREEN_WIDTH / 2 - 100, 10, 40, BLACK);
        DrawTextEx(font, "Health", (Vector2){0, 0}, 32, 2, WHITE);

        DrawFPS(SCREEN_WIDTH - 100, 10);
        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(tile);
    UnloadFont(font);
    CloseWindow();

    return 0;
}
