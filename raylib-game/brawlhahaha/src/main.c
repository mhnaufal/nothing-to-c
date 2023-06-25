#include <util.h>
#include <game.h>

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
    initALL();

    EntityManager entity_manager = initEntityManager();
    TextureManager texture_manager = initTextureManager();
    AudioManager audio_manager = initAudioManager();

    Vector2 player1_position = {100, 300};
    Vector2 player1_size = {180, 300};
    Texture2D player1_idle = loadTexture2D("../assets/img/sprite/ronin/idle.png"); // 1
    Texture2D player1_run = loadTexture2D("../assets/img/sprite/ronin/run.png");
    Texture2D background = loadTexture2D("../assets/img/background/moon.png");
    Texture2D player1_jump = loadTexture2D("../assets/img/sprite/ronin/jump.png");
    Texture2D player1_attack = loadTexture2D("../assets/img/sprite/ronin/attack.png");
    addTexture(&texture_manager, player1_idle);
    addTexture(&texture_manager, player1_run);
    addTexture(&texture_manager, background);
    addTexture(&texture_manager, player1_jump);
    addTexture(&texture_manager, player1_attack);
    Entity player1 = initEntity("Player 1", texture_manager, 1, player1_position, player1_size);
    addEntity(&entity_manager, &player1); // 1

    Vector2 player2_position = {1100, 300};
    Vector2 player2_size = {180, 300};
    Texture2D player2_idle = loadTexture2D("../assets/img/sprite/nomad/idle.png"); // 6
    Texture2D player2_run = loadTexture2D("../assets/img/sprite/nomad/run.png");
    Texture2D player2_jump = loadTexture2D("../assets/img/sprite/nomad/jump.png");
    Texture2D player2_attack = loadTexture2D("../assets/img/sprite/nomad/attack.png");
    addTexture(&texture_manager, player2_idle);
    addTexture(&texture_manager, player2_run);
    addTexture(&texture_manager, player2_jump);
    addTexture(&texture_manager, player2_attack);
    Entity player2 = initEntity("Player 2", texture_manager, 6, player2_position, player2_size);
    addEntity(&entity_manager, &player2); // 2

    Music music_bg = LoadMusicStream("../assets/audio/battle.mp3");
    Sound sound_slash = LoadSound("../assets/audio/slash.mp3");
    Sound sound_start = LoadSound("../assets/audio/ready-fight.mp3");
    addMusic(&audio_manager, music_bg);
    addSound(&audio_manager, sound_slash);
    addSound(&audio_manager, sound_start);

    GameManager game_manager = initGameManager(entity_manager, texture_manager, audio_manager); // only called once, after all other managers ready

    gameLoop(&game_manager);

    closeALL(&game_manager);

    return 0;
}
