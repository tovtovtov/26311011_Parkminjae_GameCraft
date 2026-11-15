
#include "DebugScene.h"
#include "App.h"

#include <iostream>

DebugScene::DebugScene(
    ResourceManager& resourceManager,
    InputManager& inputManager)
    : m_resourceManager(resourceManager),
    m_inputManager(inputManager)
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


    // =================================
    // 1. CSV 맵 데이터 로드
    // =================================

    bool groundLoaded = m_groundMap.LoadCSV(
        "resource/map/MapData/testmap_Ground.csv"
    );

    bool wallLoaded = m_wallMap.LoadCSV(
        "resource/map/MapData/testmap_Wall.csv"
    );

    bool wallRoofLoaded = m_wallRoofMap.LoadCSV(
        "resource/map/MapData/testmap_Roof.csv"
    );

    if (!groundLoaded || !wallLoaded || !wallRoofLoaded)
    {
        std::cerr << "Failed to load map data\n";
        return;
    }

    if (m_groundMap.GetWidth() != m_wallMap.GetWidth() ||
        m_groundMap.GetWidth() != m_wallRoofMap.GetWidth() ||
        m_groundMap.GetHeight() != m_wallMap.GetHeight() ||
        m_groundMap.GetHeight() != m_wallRoofMap.GetHeight())
    {
        std::cerr << "Map layer size mismatch\n";
        return;
    }

    // =================================
    // 2. 맵 텍스처 로드
    // =================================

    int groundTexture = textureManager.Load(
        "ground",
        "resource/map/Pixel_Art_Top_Down/Texture/TX Tileset Grass.png"
    );

    int wallTexture = textureManager.Load(
        "wall",
        "resource/map/Pixel_Art_Top_Down/Texture/TX Tileset Wall.png"
    );

    int wallRoofTexture = textureManager.Load(
        "wall_roof",
        "resource/map/Pixel_Art_Top_Down/Texture/TX Tileset Stone Ground.png"
    );

    if (groundTexture < 0 ||
        wallTexture < 0 ||
        wallRoofTexture < 0)
    {
        std::cerr << "Failed to load map textures\n";
        return;
    }


    // =================================
    // 3. 맵 렌더러 초기화
    // =================================

    m_groundRenderer.Init(
        &m_groundMap,
        groundTexture,
        256,
        256
    );

    m_wallRenderer.Init(
        &m_wallMap,
        wallTexture,
        512,
        512
    );

    m_wallRoofRenderer.Init(
        &m_wallRoofMap,
        wallRoofTexture,
        256,
        256
    );


    // =================================
    // 4. 플레이어 애니메이션 등록
    // =================================

    int playerTexture = textureManager.Load(
        "player",
        "resource/character/player/skull_knight-Sheet.png"
    );

    if (playerTexture < 0)
        return;

    // Walk
    animationManager.AddFromRow(
        "walk_down", playerTexture, 0, 6, 0.07f, 64, 64
    );

    animationManager.AddFromRow(
        "walk_left", playerTexture, 1, 6, 0.07f, 64, 64
    );

    animationManager.AddFromRow(
        "walk_right", playerTexture, 2, 6, 0.07f, 64, 64
    );

    animationManager.AddFromRow(
        "walk_up", playerTexture, 3, 6, 0.07f, 64, 64
    );

    // Idle
    animationManager.AddFromRow(
        "idle_down", playerTexture, 4, 6, 0.15f, 64, 64
    );

    animationManager.AddFromRow(
        "idle_left", playerTexture, 5, 6, 0.15f, 64, 64
    );

    animationManager.AddFromRow(
        "idle_right", playerTexture, 6, 6, 0.15f, 64, 64
    );

    animationManager.AddFromRow(
        "idle_up", playerTexture, 7, 6, 0.15f, 64, 64
    );

    // Attack
    animationManager.AddFromRow(
        "attack_down", playerTexture, 8, 6, 0.07f, 64, 64
    );

    animationManager.AddFromRow(
        "attack_up", playerTexture, 9, 6, 0.07f, 64, 64
    );

    animationManager.AddFromRow(
        "attack_left", playerTexture, 10, 6, 0.07f, 64, 64
    );

    animationManager.AddFromRow(
        "attack_right", playerTexture, 11, 6, 0.07f, 64, 64
    );


    // =================================
    // 5. 플레이어 생성
    // =================================

    m_player = new Player(
        m_inputManager,
        animationManager
    );


    // =================================
    // 6. 배경 음악
    // =================================

    m_backgroundMusic = soundManager.Load(
        "background_music",
        "resource/sound/the_mountain_retro_game.mp3"
    );

    soundManager.Play("background_music", true);
}

void DebugScene::Update()
{
    if (m_player == nullptr)
        return;

    float deltaTime =
        App::GetInstance().GetTimeSystem().GetDeltaTime();

    m_player->Update(deltaTime);
}

void DebugScene::Render()
{
    // 오브젝트 및 카메라 기능 추가 후 sort 기능 구현
    m_groundRenderer.Render();

    if (m_player != nullptr)
    {
        m_player->Render();
    }

    m_wallRoofRenderer.Render();

    m_wallRenderer.Render();
}

void DebugScene::Destroy()
{
    delete m_player;
    m_player = nullptr;
}
