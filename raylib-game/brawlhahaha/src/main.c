#include <main.h>

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
    const int SCREEN_WIDTH = 1440;
    const int SCREEN_HEIGHT = 768;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Brawlhahaha");

    Texture2D background = LoadTexture("../assets/img/background/moon.png");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextureEx(background, (Vector2){0, 0}, 0.0f, 1.0f, WHITE);

        DrawText("Brawlhahaha", SCREEN_WIDTH / 2 - 100, 10, 40, BLACK);
        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();

    return 0;
}
