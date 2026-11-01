#pragma once

class Scene;

class SceneManager
{
private:
    Scene* m_currentScene;

public:
    SceneManager();
    ~SceneManager();

    // 현재 씬 교체
    void ChangeScene(Scene* newScene);

    // 현재 씬 업데이트
    void Update();

    // 현재 씬 렌더링
    void Render();

    // 현재 씬 종료
    void Destroy();
};
