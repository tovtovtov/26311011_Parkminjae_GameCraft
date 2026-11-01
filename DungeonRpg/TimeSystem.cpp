#include "TimeSystem.h"
#include "glc2d.h"

TimeSystem::TimeSystem()
    : m_previousTime(0),
    m_currentTime(0),
    m_deltaTime(0.0f),
    m_elapsedTime(0.0f)
{
}


// 시간 시스템 초기화
void TimeSystem::Init()
{
    // 현재 시간을 기준점으로 설정
    m_previousTime = g2_TimeGetTime();
    m_currentTime = m_previousTime;

    m_deltaTime = 0.0f;
    m_elapsedTime = 0.0f;
}


// 매 프레임 시간 갱신
void TimeSystem::Update()
{
    // 현재 시간 측정
    m_currentTime = g2_TimeGetTime();

    // 이전 프레임과 현재 프레임의 시간 차이 계산
    long long elapsedMilliseconds =
        m_currentTime - m_previousTime;

    // 밀리초를 초 단위로 변환
    m_deltaTime = elapsedMilliseconds / 1000.0f;

    // 비정상적으로 긴 프레임 시간 제한
    if (m_deltaTime > 0.1f)
    {
        m_deltaTime = 0.1f;
    }

    // 전체 경과 시간 누적
    m_elapsedTime += m_deltaTime;

    // 다음 프레임을 위한 시간 갱신
    m_previousTime = m_currentTime;
}


// 프레임 사이의 경과 시간 반환
float TimeSystem::GetDeltaTime() const
{
    return m_deltaTime;
}


// 게임 시작 후 경과 시간 반환
float TimeSystem::GetElapsedTime() const
{
    return m_elapsedTime;
}
