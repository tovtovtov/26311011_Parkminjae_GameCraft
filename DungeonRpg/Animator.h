#pragma once

#include <string>
#include "AnimationManager.h"

class Animator
{
private:
    const AnimationManager& m_animationManager;
    const AnimationClip* m_currentClip;

    int m_currentFrame;
    float m_elapsedTime;

public:
    Animator(const AnimationManager& manager);

    void Play(const std::string& name);
    void Update(float deltaTime);
    void Render(const VEC2& position, const VEC2& scale) const;
};