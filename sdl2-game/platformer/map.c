#include <main.h>

/*************/
/*    Map    */
/*************/
Map loadMap(GameManager *p_game_manager)
{
    Map map;
    map.grass = loadTexture(p_game_manager, "./res/gfx/dirt.png");
    map.rock = loadTexture(p_game_manager, "./res/gfx/rock.png");
    map.water = loadTexture(p_game_manager, "./res/gfx/water.png");

    return map;
}

void drawMap(Map *p_map, GameManager *p_game_manager)
{
    SDL_Rect src = {0, 0, 32, 32};
    SDL_Rect dst = {0, 0, 32, 32};

    for (int i = 0; i < TILE_HEIGHT; i++)
    {
        for (int j = 0; j < TILE_WIDTH; j++)
        {
            p_map->tile[i][j] = level1[i][j];
            dst.x = j * 32;
            dst.y = i * 32;

            switch (p_map->tile[i][j])
            {
            case 0:
                SDL_RenderCopy(p_game_manager->renderer, p_map->grass, &src, &dst);
                break;
            case 1:
                SDL_RenderCopy(p_game_manager->renderer, p_map->rock, &src, &dst);
                break;
            case 2:
                SDL_RenderCopy(p_game_manager->renderer, p_map->water, &src, &dst);
                break;
            }
        }
    }
}
