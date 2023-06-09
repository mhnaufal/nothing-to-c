#include <main.h>

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
    initALL();

    GameManager game_manager = initGameManager();
    EntityManager entity_manager = initEntityManager();

    Vector2 player1_position = {100, 300};
    Vector2 player1_size = {180, 300};
    Entity player1 = initEntity("Player 1", "../assets/img/sprite/warrior/idle.png", player1_position, player1_size);
    addEntity(&entity_manager, &player1);
    connectEntityManagerToGameManager(&game_manager, entity_manager); // only called once

    gameLoop(&game_manager);

    closeALL(&game_manager);

    return 0;
}
