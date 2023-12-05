#include <util.h>
#include <game.h>

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
    initALL();

    EntityManager entity_manager = initEntityManager();
    TextureManager texture_manager = initTextureManager();
    AudioManager audio_manager = initAudioManager();
    UIManager ui_manager = initUIManager();

    // Player 1
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

    // Player 2
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

    // Player 1 Attack
    Vector2 attack1_size = (Vector2){ATTACK_BOX_WIDTH, ATTACK_BOX_HEIGHT};
    Entity player1_attack_box = initEntity("Player 1 Attack", texture_manager, 5, player1_position, attack1_size);
    addEntity(&entity_manager, &player1_attack_box); // 3

    // Player 2 Attack
    Vector2 attack2_size = (Vector2){ATTACK_BOX_WIDTH, ATTACK_BOX_HEIGHT};
    Entity player2_attack_box = initEntity("Player 2 Attack", texture_manager, 9, player2_position, attack2_size);
    addEntity(&entity_manager, &player2_attack_box);

    // Audio
    Music music_bg = LoadMusicStream("../assets/audio/battle.mp3");
    Sound sound_slash = LoadSound("../assets/audio/slash.mp3");
    Sound sound_start = LoadSound("../assets/audio/ready-fight.mp3");
    Sound sound_slash2 = LoadSound("../assets/audio/slash2.mp3");
    addMusic(&audio_manager, music_bg);
    addSound(&audio_manager, sound_slash);
    addSound(&audio_manager, sound_start);
    addSound(&audio_manager, sound_slash2);

    // UI
    Rectangle base_health = {0, 0, SCREEN_WIDTH, 50};
    Rectangle player1_health = {0, 0, SCREEN_WIDTH / 2, 50};
    Rectangle player2_health = {SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, 50};
    addUI(&ui_manager, base_health);
    addUI(&ui_manager, player1_health);
    addUI(&ui_manager, player2_health);

    GameManager game_manager = initGameManager(entity_manager, texture_manager, audio_manager, ui_manager); // only called once, after all other managers ready

    if (!is_game_start) {
        is_game_start = true;
        gameLoop(&game_manager);
    }

    closeALL(&game_manager);

    return 0;
}
