#include "DebugScene.h"
#include "App.h"

DebugScene::DebugScene(
    ResourceManager& resourceManager,
    InputManager& inputManager)
    : m_resourceManager(resourceManager),
    m_inputManager(inputManager),
    m_player(nullptr)
{
}

DebugScene::~DebugScene()
{
    Destroy();
}

void DebugScene::Init()
{
    auto& textureManager =
        m_resourceManager.GetTextureManager();

    auto& soundManager =
        m_resourceManager.GetSoundManager();

    auto& animationManager =
        m_resourceManager.GetAnimationManager();

    // 배경 이미지
    m_backgroundTexture = textureManager.Load(
        "debug_background",
        "resource/map/Pixel_Art_Top_Down/Scene_Overview.png"
    );

    // 사운드
    m_backgroundMusic = soundManager.Load(
        "background_music",
        "resource/sound/the_mountain_retro_game.mp3"
    );

    // 스프라이트 시트 로드
    int playerTexture = textureManager.Load(
        "player",
        "resource/character/player/skull_knight-Sheet.png"
    );

    if (playerTexture < 0)
        return;

    // 애니메이션 등록
    
    // Walk animation
    {
        animationManager.AddFromRow(
            "walk_down", playerTexture, 0, 6, 0.07f
        );
        animationManager.AddFromRow(
            "walk_left", playerTexture, 1, 6, 0.07f
        );
        animationManager.AddFromRow(
            "walk_right", playerTexture, 2, 6, 0.07f
        );
        animationManager.AddFromRow(
            "walk_up", playerTexture, 3, 6, 0.07f
        );
    }
    // Idle animation
    {
        animationManager.AddFromRow(
            "idle_down", playerTexture, 4, 6, 0.15f
        );

        animationManager.AddFromRow(
            "idle_left", playerTexture, 5, 6, 0.15f
        );

        animationManager.AddFromRow(
            "idle_right", playerTexture, 6, 6, 0.15f
        );

        animationManager.AddFromRow(
            "idle_up", playerTexture, 7, 6, 0.15f
        );
    }
    
    m_player = new Player(
        m_inputManager,
        animationManager
    );

    // 배경 음악 재생
    soundManager.Play("background_music", true);
}

void DebugScene::Update()
{
    if (m_player == nullptr)
        return;

    m_player->Update(App::GetInstance().GetTimeSystem().GetDeltaTime());
}

void DebugScene::Render()
{
    // 배경 출력
    if (m_backgroundTexture >= 0)
    {
        VEC2 position{ 0.0f, 0.0f };
        VEC2 scale{ 1.0f, 1.0f };

        g2_Draw2D(
            m_backgroundTexture,
            nullptr,
            &position,
            &scale
        );
    }

    // 플레이어 출력
    if (m_player != nullptr)
    {
        m_player->Render();
    }
}

void DebugScene::Destroy()
{
    delete m_player;
    m_player = nullptr;
}