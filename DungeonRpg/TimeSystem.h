#pragma once

class TimeSystem
{
private:
    // 이전 프레임의 시간
    long long m_previousTime;

    // 현재 프레임의 시간
    long long m_currentTime;

    // 프레임 사이에 흐른 시간 (초 단위)
    float m_deltaTime;

    // 게임 시작 후 경과 시간 (초 단위)
    float m_elapsedTime;

public:
    TimeSystem();

    // 시간 시스템 초기화
    void Init();

    // 매 프레임 시간 갱신
    void Update();

    // 프레임 사이의 경과 시간 반환
    float GetDeltaTime() const;

    // 게임 시작 후 경과 시간 반환
    float GetElapsedTime() const;
};