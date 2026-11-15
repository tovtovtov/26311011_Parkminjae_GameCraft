
#pragma once

#include "Scene.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Player.h"

#include "MapData.h"
#include "MapRenderer.h"

class DebugScene : public Scene
{
private:
    ResourceManager& m_resourceManager;
    InputManager& m_inputManager;

    Player* m_player = nullptr;

    // ∏  µ•¿Ã≈Õ
    MapData m_groundMap;
    MapData m_wallMap;
    MapData m_wallRoofMap;

    // ∏  ∑ª¥ı∑Ø
    MapRenderer m_groundRenderer;
    MapRenderer m_wallRenderer;
    MapRenderer m_wallRoofRenderer;

    // ªÁøÓµÂ
    int m_backgroundMusic = -1;

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
