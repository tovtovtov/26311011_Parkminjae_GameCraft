#pragma once
#include "GameTime.h"
#include "GraphicEngine.h"

class GameInput;
class GameScene;

class App
{
public:
	int Init();
	void Destory();
	int Update();
	int Render();

	int Run();

protected:
	GraphicEngine m_graphicEngine{};
	GameTime m_gameTime{};
	GameInput* m_pGameInput{};
	GameScene* m_pGameScene{}; // 현재의 게임씬
};

extern App* g_pApp;