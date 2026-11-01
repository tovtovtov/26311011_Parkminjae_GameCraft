#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager()
    : m_currentScene(nullptr)
{
}

SceneManager::~SceneManager()
{
    Destroy();
}

void SceneManager::ChangeScene(Scene* newScene)
{
    if (newScene == nullptr)
    {
        return;
    }

    // 기존 씬 종료 및 메모리 해제
    if (m_currentScene != nullptr)
    {
        m_currentScene->Destroy();

        delete m_currentScene;
        m_currentScene = nullptr;
    }

    // 새로운 씬 등록 및 초기화
    m_currentScene = newScene;
    m_currentScene->Init();
}

void SceneManager::Update()
{
    if (m_currentScene != nullptr)
    {
        m_currentScene->Update();
    }
}

void SceneManager::Render()
{
    if (m_currentScene != nullptr)
    {
        m_currentScene->Render();
    }
}

void SceneManager::Destroy()
{
    if (m_currentScene != nullptr)
    {
        m_currentScene->Destroy();

        delete m_currentScene;
        m_currentScene = nullptr;
    }
}