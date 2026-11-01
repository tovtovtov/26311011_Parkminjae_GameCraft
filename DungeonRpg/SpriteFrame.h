#pragma once
#include "glc2d.h"

class SpriteFrame
{
private:
    RECT m_srcRect;
    float m_duration;

public:
    SpriteFrame(const RECT& srcRect, float duration);

    const RECT& GetSrcRect() const;
    float GetDuration() const;
};