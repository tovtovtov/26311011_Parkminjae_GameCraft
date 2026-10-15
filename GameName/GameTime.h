#pragma once
class GameTime
{
public:
	int Init();
	int Update();

	long long biginTime{};
	long long eplapsedTime{};
	long long deltatime{}; // millisecond
};

