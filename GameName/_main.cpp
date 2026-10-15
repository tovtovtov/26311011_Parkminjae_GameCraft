#include <iostream>
#include "App.h"
using namespace std;

App* g_pApp;

int main(void)
{
	App app;
	g_pApp = &app;

	if (g_pApp->Init())
		return 0;

	auto r = g_pApp->Run();
	// 에러 처리
	{
		
	}
	return 0;
}