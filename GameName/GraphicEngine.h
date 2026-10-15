#pragma once
#include <glc2d.h>

class GraphicEngine
{
public:
	// 기본 함수
	int Init();
	void Destory();
	int Run();
	static int Update();
	static int Render();

	void SetColor(unsigned long color);
};

