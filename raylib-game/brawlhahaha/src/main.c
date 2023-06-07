#include <main.h>

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
    const int SCREEN_WIDTH = 1440;
    const int SCREEN_HEIGHT = 768;
    const float GRAVITY = 2.5;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Brawlhahaha");

    Texture2D background = LoadTexture("../assets/img/background/moon.png");
    Texture2D tile = LoadTexture("../assets/img/tile/dungeon.png");

    /*   */
    size_t PLAYER_WIDTH = 100;
    size_t PLAYER_HEIGHT = 180;
    ComponentTransform ct1 = {(Vector2){100, 300}, (Vector2){0, 10}};
    Rectangle rt1 = {ct1.position.x, ct1.position.y, PLAYER_WIDTH, PLAYER_HEIGHT};
    Entity e1 = {"Player 1", &ct1, &rt1, NULL};

    e1.funcs.init_entity = init_entity("COK", NULL, NULL, NULL);
    /*   */

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

        DrawRectangleRec(*e1.m_shape, RED);
        DrawText("Brawlhahaha", SCREEN_WIDTH / 2 - 100, 10, 40, BLACK);
        DrawFPS(SCREEN_WIDTH - 100, 10);
        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();

    return 0;
}

// int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
// {
//     const int SCREEN_WIDTH = 1440;
//     const int SCREEN_HEIGHT = 768;

//     InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Brawlhahaha");

//     Texture2D background = LoadTexture("../assets/img/background/moon.png");
//     Texture2D tile = LoadTexture("../assets/img/tile/dungeon.png");
//     Font font = LoadFont("../assets/font/opensans.ttf");

//     Vector2 player_position = {(float)500, (float)100};
//     float player_velocity = 10;
//     float gravity = 2.5;
//     Vector2 attack_box_postiion = {player_position.x, player_position.y};
//     Vector2 attack_box_size = {(float)300, (float)50};
//     bool facing_right = true;
//     // Rectangle attack_box = {attack_box_postiion.x, attack_box_postiion.y, attack_box_size.x, attack_box_size.y};

//     SetTargetFPS(60);

//     while (!WindowShouldClose())
//     {
//         BeginDrawing();
//         ClearBackground(RAYWHITE);

//         DrawTextureEx(background, (Vector2){0, 0}, 0.0f, 1.0f, WHITE);

//         for (int i = -20; i <= SCREEN_WIDTH; i += 48)
//         {
//             DrawTextureRec(tile, (Rectangle){0, 0, 64, 64}, (Vector2){i, SCREEN_HEIGHT - 140}, WHITE);
//             DrawTextureRec(tile, (Rectangle){0, 0, 64, 64}, (Vector2){i, SCREEN_HEIGHT - 100}, WHITE);
//             DrawTextureRec(tile, (Rectangle){0, 0, 64, 64}, (Vector2){i, SCREEN_HEIGHT - 60}, WHITE);
//         }

//         /*  */
//         if (player_position.x <= 0)
//             player_position.x = 0;
//         if (player_position.x + 100 >= SCREEN_WIDTH)
//             player_position.x = SCREEN_WIDTH - 100;
//         if (player_position.y <= 0)
//             player_position.y = 0;

//         if (IsKeyDown(KEY_A))
//         {
//             player_position.x -= 5.0f;
//             facing_right = false;
//         }
//         if (IsKeyDown(KEY_D))
//         {
//             player_position.x += 5.0f;
//             facing_right = true;
//         }
//         if (IsKeyPressed(KEY_W))
//         {
//             player_velocity = -20.0f;
//         }

//         DrawRectangleV(player_position, (Vector2){100, 180}, RED);
//         player_position.y += player_velocity;
//         if (player_position.y + 180 + player_velocity >= SCREEN_HEIGHT - 125)
//         {
//             player_velocity = 0;
//         }
//         else
//         {
//             player_velocity += gravity;
//         }

//         attack_box_postiion.x = player_position.x;
//         attack_box_postiion.y = player_position.y;
//         if (IsKeyPressed(KEY_J) && facing_right)
//         {
//             DrawRectangleV(attack_box_postiion, attack_box_size, BLUE);
//         }
//         if (IsKeyPressed(KEY_J) && !facing_right)
//         {
//             DrawRectangleV((Vector2){attack_box_postiion.x - attack_box_size.x + 100, attack_box_postiion.y}, (Vector2){attack_box_size.x, attack_box_size.y}, GREEN);
//         }
//         /*  */

//         DrawText("Brawlhahaha", SCREEN_WIDTH / 2 - 100, 10, 40, BLACK);
//         DrawTextEx(font, "Health", (Vector2){0, 0}, 32, 2, WHITE);

//         DrawFPS(SCREEN_WIDTH - 100, 10);
//         EndDrawing();
//     }

//     UnloadTexture(background);
//     UnloadTexture(tile);
//     UnloadFont(font);
//     CloseWindow();

//     return 0;
// }
