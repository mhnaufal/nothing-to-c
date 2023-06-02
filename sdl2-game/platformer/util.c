#include <main.h>

/*****************/
/* Initial Setup */
/*****************/
bool initALL(void)
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

bool initWindow(GameManager *p_sdl_game, const char *p_title)
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

void cleanUpSDL(GameManager *p_sdl_game)
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

/************/
/* Renderer */
/************/
SDL_Texture *loadTexture(GameManager *p_sdl_game, const char *p_path)
{
    SDL_Texture *texture = IMG_LoadTexture(p_sdl_game->renderer, p_path);
    if (texture == NULL)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to load texture: %s]\n", SDL_GetError());
    }

    return texture;
}

void clearRenderer(GameManager *p_sdl_game)
{
    SDL_RenderClear(p_sdl_game->renderer);
}

void renderTexture(GameManager *p_sdl_game)
{
    SDL_RenderPresent(p_sdl_game->renderer);
}

/********/
/* Font */
/********/
TTF_Font *initFont(const char *p_font, int p_size)
{
    TTF_Font *font = TTF_OpenFont(p_font, p_size);
    if (!font)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to init load TTF font: %s]\n", TTF_GetError());
    }

    return font;
}

void drawText(TTF_Font *p_font, GameManager *p_sdl_game, const char *p_text, int p_x, int p_y, int p_r, int p_g, int p_b, int p_a)
{
    SDL_Color color = {p_r, p_g, p_b, p_a};

    SDL_Surface *text_surface = TTF_RenderText_Solid(p_font, p_text, color);
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

/*********/
/* Audio */
/*********/
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

void playSound(Mix_Chunk *p_sound, int p_channel, int p_loop)
{
    int play = Mix_PlayChannel(p_channel, p_sound, p_loop);
    if (play != 0)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to play the sound: %s]\n", Mix_GetError());
    }
}

void playMusic(Mix_Music *p_music, int p_loop)
{
    int play = Mix_PlayMusic(p_music, p_loop);
    if (play != 0)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "[Failed to play the music: %s]\n", Mix_GetError());
    }
}

void clearSound(Mix_Chunk *p_sound)
{
    Mix_FreeChunk(p_sound);
}

void clearMusic(Mix_Music *p_music)
{
    Mix_FreeMusic(p_music);
}
