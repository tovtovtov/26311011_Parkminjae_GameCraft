
#include "Player.h"
#include <cmath>

Player::Player(
    InputManager& inputManager,
    const AnimationManager& animationManager)
    : m_inputManager(inputManager),
    m_animator(animationManager),
    m_position{ 640.0f, 360.0f },
    m_moveSpeed(150.0f),
    m_facingDirection("down"),
    m_isAttacking(false)
{
    m_animator.Play("idle_down");
}

void Player::Update(float deltaTime)
{
    // =================================
    // 1. 공격 중인 경우
    // =================================

    if (m_isAttacking)
    {
        m_animator.Update(deltaTime);

        if (m_animator.IsFinished())
        {
            if (m_inputManager.IsPress('J'))
            {
                m_animator.Play(
                    "attack_" + m_facingDirection,
                    false
                );
            }
            else
            {
                m_isAttacking = false;
            }
        }

        return;
    }


    // =================================
    // 2. 이동 입력
    // =================================

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


    // =================================
    // 3. 바라보는 방향 갱신
    // =================================

    if (moveX < 0.0f)
        m_facingDirection = "left";
    else if (moveX > 0.0f)
        m_facingDirection = "right";
    else if (moveY < 0.0f)
        m_facingDirection = "up";
    else if (moveY > 0.0f)
        m_facingDirection = "down";


    // =================================
    // 4. 공격 입력
    // =================================

    if (m_inputManager.IsDown('J'))
    {
        m_isAttacking = true;

        m_animator.Play(
            "attack_" + m_facingDirection,
            false
        );

        m_animator.Update(deltaTime);

        return;
    }


    // =================================
    // 5. 이동 및 애니메이션
    // =================================

    bool isMoving =
        (moveX != 0.0f || moveY != 0.0f);

    if (isMoving)
    {
        float length = std::sqrt(
            moveX * moveX + moveY * moveY
        );

        moveX /= length;
        moveY /= length;

        m_position.x +=
            moveX * m_moveSpeed * deltaTime;

        m_position.y +=
            moveY * m_moveSpeed * deltaTime;

        m_animator.Play(
            "walk_" + m_facingDirection
        );
    }
    else
    {
        m_animator.Play(
            "idle_" + m_facingDirection
        );
    }

    m_animator.Update(deltaTime);
}

void Player::Render() const
{
    VEC2 scale{ 2.0f, 2.0f };

    m_animator.Render(m_position, scale);
}
