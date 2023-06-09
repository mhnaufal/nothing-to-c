#include <main.h>

void initALL(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    InitAudioDevice();
    SetTargetFPS(60);
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

Texture2D loadTexture2D(char *filename)
{
    Texture2D t = LoadTexture(filename);
    return t;
}
