#include <main.h>

int main(int argc, char *argv[])
{
    initSDL();

    GameState game_state = {true, false, false, false, false, false};
    SDLGame sdl_game = {NULL, NULL, NULL, NULL};
    TimeManager time_manager = {60, 1000 / time_manager.FPS, 0, 0};

    initWindow(&sdl_game, "Catty The Cat");
    playGame(&sdl_game, game_state, time_manager);
    cleanUpSDL(&sdl_game);

    SDL_Quit();

    return 0;
}

bool initSDL()
{
    bool is_success = true;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_CRITICAL, "[Failed to init SDL2: %s]\n", SDL_GetError());
        is_success = false;
    }

    if (IMG_Init(IMG_INIT_PNG) < 0)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to init SDL2 Image for PNG: %s]\n", IMG_GetError());
        is_success = false;
    }

    if (TTF_Init() < 0)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to init SDL2 TTF Font: %s]\n", TTF_GetError());
        is_success = false;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) < 0)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to init SDL2 mixer audio: %s]\n", Mix_GetError());
        is_success = false;
    }

    return is_success;
}

bool initWindow(SDLGame *p_sdl_game, const char *p_title)
{
    bool is_success = true;

    p_sdl_game->window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (p_sdl_game->window == NULL)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_CRITICAL, "[Failed to init SDL2 window: %s]\n", SDL_GetError());
        is_success = false;
    }

    p_sdl_game->renderer = SDL_CreateRenderer(p_sdl_game->window, -1, SDL_RENDERER_ACCELERATED);
    if (p_sdl_game->renderer == NULL)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to init SDL2 renderer: %s]\n", SDL_GetError());
        is_success = false;
    }

    return is_success;
}

void cleanUpSDL(SDLGame *p_sdl_game)
{
    TTF_CloseFont(p_sdl_game->font);
    SDL_DestroyTexture(p_sdl_game->texture);
    SDL_DestroyRenderer(p_sdl_game->renderer);
    SDL_DestroyWindow(p_sdl_game->window);

    p_sdl_game->texture = NULL;
    p_sdl_game->renderer = NULL;
    p_sdl_game->window = NULL;

    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void playGame(SDLGame *sdl_game, GameState game_state, TimeManager time_manager)
{
    SDL_FRect entity_size = {WINDOW_WIDTH / 2 - PIXEL_WIDTH, WINDOW_HEIGHT / 2 - PIXEL_HEIGHT, PIXEL_WIDTH, PIXEL_HEIGHT};
    SDL_FRect new_size = {0, 0, 0, 0};

    SDL_Texture *texture1 = loadTexture(sdl_game, "./res/gfx/cat1.png");
    Velocity velo1 = {0, 1.3};
    Entity cat1 = initEntity(entity_size, texture1, velo1);

    Map map1 = loadMap(sdl_game);

    Mix_Chunk *sound1 = loadSound("./res/audio/audio1.wav");
    Mix_Music *music1 = loadMusic("./res/audio/horror.mp3");

    playMusic(music1);

    SDL_Event event;

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

        clearRenderer(sdl_game);

        drawMap(&map1, sdl_game);
        updateEntity(&cat1, new_size);
        drawEntity(sdl_game, &cat1);
        drawText(sdl_game, "Cat Life: ", 5, 5, 255, 255, 255, 24);
        playSound(sound1);

        char str[2];
        sprintf(str, "%d", PLAYER_LIFE);
        drawText(sdl_game, str, 100, 5, 255, 255, 255, 24);

        renderTexture(sdl_game);

        time_manager.FRAME_TIME = SDL_GetTicks() - time_manager.FRAME_START;

        if (time_manager.FRAME_DELAY >= time_manager.FRAME_TIME)
        {
            SDL_Delay(time_manager.FRAME_DELAY - time_manager.FRAME_TIME);
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "[FPS] %d\n", 60 - time_manager.FRAME_TIME);
        }
    }
}

SDL_Texture *loadTexture(SDLGame *p_sdl_game, const char *p_path)
{
    SDL_Texture *texture = IMG_LoadTexture(p_sdl_game->renderer, p_path);
    if (texture == NULL)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to load texture: %s]\n", SDL_GetError());
    }

    return texture;
}

void clearRenderer(SDLGame *p_sdl_game)
{
    SDL_RenderClear(p_sdl_game->renderer);
}

void renderTexture(SDLGame *p_sdl_game)
{
    SDL_RenderPresent(p_sdl_game->renderer);
}

void drawText(SDLGame *p_sdl_game, const char *p_text, int p_x, int p_y, int p_r, int p_g, int p_b, int p_size)
{
    TTF_Font *font = TTF_OpenFont("./res/font/open_sans.ttf", p_size);
    if (!font)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to init load TTF font: %s]\n", TTF_GetError());
    }

    SDL_Color color = {p_r, p_g, p_b, 255};

    SDL_Surface *text_surface = TTF_RenderText_Solid(font, p_text, color);
    if (!text_surface)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to render font text: %s]\n", TTF_GetError());
    }

    p_sdl_game->texture = SDL_CreateTextureFromSurface(p_sdl_game->renderer, text_surface);

    SDL_Rect dst = {p_x, p_y, text_surface->w, text_surface->h};
    SDL_FreeSurface(text_surface);
    SDL_RenderCopy(p_sdl_game->renderer, p_sdl_game->texture, NULL, &dst);
    SDL_DestroyTexture(p_sdl_game->texture);
}

Mix_Chunk *loadSound(const char *p_audio_file)
{
    Mix_Chunk *sound = Mix_LoadWAV(p_audio_file);
    if (!sound)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to load the sound: %s]\n", Mix_GetError());
    }

    return sound;
}

Mix_Music *loadMusic(const char *p_audio_file)
{
    Mix_Music *music = Mix_LoadMUS(p_audio_file);
    if (!music)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to load the music: %s]\n", Mix_GetError());
    }

    return music;
}

void playSound(Mix_Chunk *p_sound)
{
    int play = Mix_PlayChannel(-1, p_sound, 0);
    if (play != 0)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to play the sound: %s]\n", Mix_GetError());
    }
}

void playMusic(Mix_Music *p_music)
{
    int play = Mix_PlayMusic(p_music, -1);
    if (play != 0)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to play the music: %s]\n", Mix_GetError());
    }
}
