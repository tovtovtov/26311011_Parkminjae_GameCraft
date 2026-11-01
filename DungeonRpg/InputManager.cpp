#include "InputManager.h"
#include "glc2d.h"

InputManager::InputManager()
    : m_keyboard(nullptr)
{
}

void InputManager::Update()
{
    m_keyboard = g2_GetKeyboard();
}

bool InputManager::IsDown(int key) const
{
    if (m_keyboard == nullptr || key < 0 || key >= 256)
    {
        return false;
    }

    return m_keyboard[key] == EINPUT_DOWN;
}

bool InputManager::IsPress(int key) const
{
    if (m_keyboard == nullptr || key < 0 || key >= 256)
    {
        return false;
    }

    return m_keyboard[key] == EINPUT_PRESS;
}

bool InputManager::IsUp(int key) const
{
    if (m_keyboard == nullptr || key < 0 || key >= 256)
    {
        return false;
    }

    return m_keyboard[key] == EINPUT_UP;
}