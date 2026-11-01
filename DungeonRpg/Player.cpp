#include "Player.h"
#include <cmath>

Player::Player(
    InputManager& inputManager,
    const AnimationManager& animationManager)
    : m_inputManager(inputManager),
    m_animator(animationManager),
    m_position{ 640.0f, 360.0f },
    m_moveSpeed(150.0f),
    m_facingDirection("down")
{
    m_animator.Play("idle_down");
}

void Player::Update(float deltaTime)
{
    float moveX = 0.0f;
    float moveY = 0.0f;

    if (m_inputManager.IsPress('W'))
        moveY -= 1.0f;

    if (m_inputManager.IsPress('S'))
        moveY += 1.0f;

    if (m_inputManager.IsPress('A'))
        moveX -= 1.0f;

    if (m_inputManager.IsPress('D'))
        moveX += 1.0f;

    bool isMoving = (moveX != 0.0f || moveY != 0.0f);

    if (isMoving)
    {
        float length = std::sqrt(
            moveX * moveX + moveY * moveY
        );

        moveX /= length;
        moveY /= length;

        m_position.x += moveX * m_moveSpeed * deltaTime;
        m_position.y += moveY * m_moveSpeed * deltaTime;

        // 바라보는 방향 갱신
        if (moveX < 0.0f)
            m_facingDirection = "left";
        else if (moveX > 0.0f)
            m_facingDirection = "right";
        else if (moveY < 0.0f)
            m_facingDirection = "up";
        else if (moveY > 0.0f)
            m_facingDirection = "down";

        m_animator.Play("walk_" + m_facingDirection);
    }
    else
    {
        m_animator.Play("idle_" + m_facingDirection);
    }

    m_animator.Update(deltaTime);
}

void Player::Render() const
{
    VEC2 scale{ 2.0f, 2.0f };

    m_animator.Render(m_position, scale);
}