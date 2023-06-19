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

Texture2D loadTexture2D(char *filename, TextureManager *texture_manager)
{
    Texture2D t = LoadTexture(filename);

    return t;
}

TextureManager initTextureManager()
{
    TextureManager tm;
    tm.total = 0;

    return tm;
}

int addTexture(TextureManager *texture_manager, Texture2D texture)
{
    texture_manager->total++;
    texture_manager->m_textures[texture_manager->total] = texture;

    return texture_manager->total;
}

void freeALL(GameManager *game_manager)
{
    for (int i = 0; i < game_manager->texture_manager->total; i++)
    {
        deleteEntity(game_manager->entity_manager, i);
        UnloadTexture(game_manager->texture_manager->m_textures[i]);
    }
}