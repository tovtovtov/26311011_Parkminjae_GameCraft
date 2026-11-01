#pragma once

#include "Scene.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Player.h"

class DebugScene : public Scene
{
private:
    ResourceManager& m_resourceManager;
    InputManager& m_inputManager;

    Player* m_player;

    // 임시 추가 추후 삭제 필요
    int m_backgroundTexture = 0;
    int m_backgroundMusic = 0;

public:
    DebugScene(
        ResourceManager& resourceManager,
        InputManager& inputManager
    );

    ~DebugScene() override;

    void Init() override;
    void Update() override;
    void Render() override;
    void Destroy() override;
};