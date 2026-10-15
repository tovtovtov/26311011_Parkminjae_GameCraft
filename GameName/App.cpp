#include "App.h"
#include "GameInput.h"
#include "GameScene.h"

int App::Init()
{
	// glc2d 초기화
	if (0 > m_graphicEngine.Init())
		return -1;

	// time 관련 초기화
	m_gameTime.Init();

	// Input 초기화
	m_pGameInput = new GameInput;
	if (0 > m_pGameInput->Init())
	{
		Destory();
		return -1;
	}

	// GameScene 초기화
	m_pGameScene = new GameScene;
	if (0 > m_pGameScene->Init())
	{
		Destory();
		return -1;
	}

	return 0;
}

void App::Destory()
{
	if (m_pGameInput) {
		delete m_pGameInput; m_pGameInput = nullptr;
	}
	if (m_pGameScene) {
		delete m_pGameScene; m_pGameScene = nullptr;
	}
		
}

int App::Update()
{
	// time 관련 업데이트
	m_gameTime.Update();
	// Input 업데이트
	if (0 > m_pGameScene->Update())
	{
		return -1;
	}
	// GameScene 업데이트
	if (0 > m_pGameScene->Update())
	{
		return -1;
	}

	return 0;
}

int App::Render()
{
	// GameScene 렌더링
	if (0 > m_pGameScene->Render())
	{
		return -2;
	}
	// GameScene 업데이트
	if (0 > m_pGameScene->Render())
	{
		return -2;
	}

	return 0;
}

int App::Run()
{
	m_graphicEngine.Run();

	this->Destory();

	return 0;
}
