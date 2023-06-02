#include <main.h>

/**************/
/*    Game    */
/**************/
void mainLoop(GameManager *p_game_manager, GameState game_state, TimeManager time_manager)
{
    SDL_FRect entity_size = {WINDOW_WIDTH / 2 - PIXEL_WIDTH, WINDOW_HEIGHT / 2 - PIXEL_HEIGHT, PIXEL_WIDTH, PIXEL_HEIGHT};
    SDL_FRect new_size = {0, 0, 0, 0};

    SDL_Texture *texture1 = loadTexture(p_game_manager, "./res/gfx/cat1.png");
    Velocity velo1 = {0, 1.3};
    Entity cat1 = initEntity(entity_size, texture1, velo1);

    Map map1 = loadMap(p_game_manager);

    TTF_Font *font1 = initFont("./res/font/open_sans.ttf", 24);

    Mix_Chunk *sound1 = loadSound("./res/audio/audio1.wav");
    Mix_Music *music1 = loadMusic("./res/audio/horror.mp3");

    SDL_Event event;

    playMusic(music1, -1);

    while (!game_state.Exit)
    {
        time_manager.FRAME_START = SDL_GetTicks();

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                game_state.Exit = true;
            }
            playerMove(&cat1, &event);
        }

        clearRenderer(p_game_manager);

        drawMap(&map1, p_game_manager);

        updateEntity(&cat1, new_size);
        drawEntity(p_game_manager, &cat1);

        drawText(font1, p_game_manager, "Cat life: ", 0, 5, 255, 255, 255, 255);
        char str[2];
        sprintf(str, "%d", PLAYER_LIFE);
        drawText(font1, p_game_manager, str, 100, 5, 255, 255, 255, 255);

        // playSound(sound1, -1, 0);

        renderTexture(p_game_manager);

        time_manager.FRAME_TIME = SDL_GetTicks() - time_manager.FRAME_START;

        if (time_manager.FRAME_DELAY >= time_manager.FRAME_TIME)
        {
            SDL_Delay(time_manager.FRAME_DELAY - time_manager.FRAME_TIME);
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "[FPS] %d\n", 60 - time_manager.FRAME_TIME);
        }
    }

    clearSound(sound1);
    clearMusic(music1);
}
