#include "App.h"
#include "glc2d.h"
#include "DebugScene.h"

// 현재 App 객체를 가리키는 포인터
App* App::s_instance = nullptr;


// 생성자
App::App()
    : m_isInitialized(false)
{
}


// 소멸자
App::~App()
{
    Destroy();
}


// 게임 실행
int App::Run()
{
    if (!Init())
    {
        return -1;
    }

    // 엔진의 게임 루프 실행
    int result = g2_Run();

    // 게임 루프 종료 후 자원 정리
    Destroy();

    return result;
}


// 초기화
bool App::Init()
{
    // 현재 App 객체 등록
    s_instance = this;

    // 엔진 SDK 초기화
    g2_InitSdk();

    // 게임 윈도우 생성
    g2_CreateWin(
        100, 100,       // 윈도우 위치
        1280, 720,      // 화면 크기
        "DungeonRpg",   // 윈도우 이름
        true,           // 윈도우 모드
        1.0f            // 화면 배율
    );

    // 시간 시스템 초기화
    m_timeSystem.Init();

    // 엔진에 Update와 Render 콜백 등록
    g2_SetFrameMove(&App::FrameMoveCallback);
    g2_SetRender(&App::RenderCallback);

    m_sceneManager.ChangeScene(
        new DebugScene(m_resourceManager, m_inputManager)
    );

    m_isInitialized = true;


    return true;
}


// 종료
void App::Destroy()
{
    if (!m_isInitialized)
    {
        return;
    }

    // 씬이 사용 중인 리소스보다 먼저 종료되어야 함
    m_sceneManager.Destroy();

    m_resourceManager.ReleaseAll();

    g2_DestroyWin();

    m_isInitialized = false;
    s_instance = nullptr;
}


// 엔진에서 호출하는 Update 콜백
int App::FrameMoveCallback()
{
    if (s_instance != nullptr)
    {
        s_instance->Update();
    }

    return 0;
}


// 엔진에서 호출하는 Render 콜백
int App::RenderCallback()
{
    if (s_instance != nullptr)
    {
        s_instance->Render();
    }

    return 0;
}


void App::Update()
{
    m_timeSystem.Update();

    m_inputManager.Update();

    m_sceneManager.Update();
}

void App::Render()
{
    m_sceneManager.Render();
}