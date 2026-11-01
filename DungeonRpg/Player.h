#pragma once

#include "InputManager.h"
#include "Animator.h"
#include <string>

class Player
{
private:
    InputManager& m_inputManager;
    Animator m_animator;

    VEC2 m_position;
    float m_moveSpeed;

    std::string m_facingDirection;

public:
    Player(
        InputManager& inputManager,
        const AnimationManager& animationManager
    );

    void Update(float deltaTime);
    void Render() const;
};