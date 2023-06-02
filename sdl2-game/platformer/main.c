#include <main.h>

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
    initALL();

    GameState game_state = {true, false, false, false, false, false};
    GameManager game_manager = {NULL, NULL, NULL, NULL};
    TimeManager time_manager = {60, 1000 / time_manager.FPS, 0, 0};

    initWindow(&game_manager, "Catty The Cat");
    mainLoop(&game_manager, game_state, time_manager);
    cleanUpSDL(&game_manager);

    SDL_Quit();

    return 0;
}
