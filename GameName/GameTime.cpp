#include "GameTime.h"
#include <chrono>

using namespace std;

int GameTime::Init()
{
	//biginTime = chrono::system_clock::now(); 캐스팅 필요
	eplapsedTime = {};
	deltatime = {};

	return 0;
}

int GameTime::Update()
{
	// 업데이트 목록
	eplapsedTime = {};
	deltatime = {};
	return 0;
}