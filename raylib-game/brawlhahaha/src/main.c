#include <main.h>

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
    initALL();

    GameManager game_manager = initGameManager();
    EntityManager entity_manager = initEntityManager();
    TextureManager texture_manager = initTextureManager();

    Vector2 player1_position = {100, 300};
    Vector2 player1_size = {180, 300};

    Texture2D player1_idle = loadTexture2D("../assets/img/sprite/ronin/idle.png", &texture_manager);
    Texture2D player1_run = loadTexture2D("../assets/img/sprite/ronin/run.png", &texture_manager);
    addTexture(&texture_manager, player1_idle);
    addTexture(&texture_manager, player1_run);

    Entity player1 = initEntity("Player 1", texture_manager, 1, player1_position, player1_size);

    addEntity(&entity_manager, &player1);

    connectEntityManagerToGameManager(&game_manager, entity_manager); // only called once and last one after all entity already added or deleted
    connectTextureManagerToGameManager(&game_manager, texture_manager);

    gameLoop(&game_manager);

    closeALL(&game_manager);

    return 0;
}
