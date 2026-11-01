#include "Animator.h"
#include "glc2d.h"

Animator::Animator(const AnimationManager& manager)
    : m_animationManager(manager),
    m_currentClip(nullptr),
    m_currentFrame(0),
    m_elapsedTime(0.0f)
{
}

void Animator::Play(const std::string& name)
{
    const AnimationClip* clip = m_animationManager.Get(name);

    if (clip == nullptr)
        return;

    // 이미 재생 중인 애니메이션이면 초기화하지 않음
    if (m_currentClip == clip)
        return;

    m_currentClip = clip;
    m_currentFrame = 0;
    m_elapsedTime = 0.0f;
}

void Animator::Update(float deltaTime)
{
    if (m_currentClip == nullptr)
        return;

    if (m_currentClip->GetFrameCount() == 0)
        return;

    m_elapsedTime += deltaTime;

    while (m_elapsedTime >=
        m_currentClip->GetFrame(m_currentFrame).GetDuration())
    {
        m_elapsedTime -=
            m_currentClip->GetFrame(m_currentFrame).GetDuration();

        m_currentFrame++;

        if (m_currentFrame >= m_currentClip->GetFrameCount())
            m_currentFrame = 0;
    }
}

void Animator::Render(
    const VEC2& position,
    const VEC2& scale) const
{
    if (m_currentClip == nullptr)
        return;

    const SpriteFrame& frame =
        m_currentClip->GetFrame(m_currentFrame);

    g2_Draw2D(
        m_currentClip->GetTextureKey(),
        &frame.GetSrcRect(),
        &position,
        &scale
    );
}