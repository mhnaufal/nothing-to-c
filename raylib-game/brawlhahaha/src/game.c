#include <game.h>

void drawTile(Texture2D *tile)
{
    for (int i = -20; i <= SCREEN_WIDTH; i += 48)
    {
        DrawTextureRec(*tile, (Rectangle){0, 0, 64, 64}, (Vector2){i, SCREEN_HEIGHT - 140}, WHITE);
        DrawTextureRec(*tile, (Rectangle){0, 0, 64, 64}, (Vector2){i, SCREEN_HEIGHT - 100}, WHITE);
        DrawTextureRec(*tile, (Rectangle){0, 0, 64, 64}, (Vector2){i, SCREEN_HEIGHT - 60}, WHITE);
    }
}
