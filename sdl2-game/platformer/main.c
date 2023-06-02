#include <main.h>

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
    initALL();

    GameState game_state = {true, false, false, false, false, false};
    GameManager sdl_game = {NULL, NULL, NULL, NULL};
    TimeManager time_manager = {60, 1000 / time_manager.FPS, 0, 0};

    initWindow(&sdl_game, "Catty The Cat");
    playGame(&sdl_game, game_state, time_manager);
    cleanUpSDL(&sdl_game);

    SDL_Quit();

    return 0;
}
