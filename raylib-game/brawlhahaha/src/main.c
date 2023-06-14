#include <main.h>

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
    initALL();

    EntityManager entity_manager = initEntityManager();
    TextureManager texture_manager = initTextureManager();

    Vector2 player1_position = {100, 300};
    Vector2 player1_size = {180, 300};

    Texture2D player1_idle = loadTexture2D("../assets/img/sprite/ronin/idle.png", &texture_manager);
    Texture2D player1_run = loadTexture2D("../assets/img/sprite/ronin/run.png", &texture_manager);
    Texture2D background = loadTexture2D("../assets/img/background/moon.png", &texture_manager);
    Texture2D player1_jump = loadTexture2D("../assets/img/sprite/ronin/jump.png", &texture_manager);
    addTexture(&texture_manager, player1_idle);
    addTexture(&texture_manager, player1_run);
    addTexture(&texture_manager, background);
    addTexture(&texture_manager, player1_jump);

    Entity player1 = initEntity("Player 1", texture_manager, 1, player1_position, player1_size);
    addEntity(&entity_manager, &player1);

    GameManager game_manager = initGameManager(entity_manager, texture_manager); // only called once, after all other managers ready

    gameLoop(&game_manager);

    closeALL(&game_manager);

    return 0;
}
