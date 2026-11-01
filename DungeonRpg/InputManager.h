#pragma once

class InputManager
{
private:
    const unsigned char* m_keyboard;

public:
    InputManager();

    // 키보드 상태 갱신
    void Update();

    // 키를 누른 순간인지 확인
    bool IsDown(int key) const;

    // 키를 누르고 있는지 확인
    bool IsPress(int key) const;

    // 키를 뗀 순간인지 확인
    bool IsUp(int key) const;
};