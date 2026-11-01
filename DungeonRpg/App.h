#pragma once

#include "TimeSystem.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "InputManager.h"

class App
{
private:
    static App* s_instance;

    bool m_isInitialized;

    // 게임 시스템
    TimeSystem m_timeSystem;
    ResourceManager m_resourceManager;
    SceneManager m_sceneManager;
    InputManager m_inputManager;

private:
    static int FrameMoveCallback();
    static int RenderCallback();

    void Update();
    void Render();

public:
    App();
    ~App();

    int Run();

    bool Init();
    void Destroy();

    static App& GetInstance()
    {
        return *s_instance;
    }

    TimeSystem& GetTimeSystem()
    {
        return m_timeSystem;
    }
};