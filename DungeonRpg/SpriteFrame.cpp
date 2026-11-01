#include "SpriteFrame.h"

SpriteFrame::SpriteFrame(const RECT& srcRect, float duration)
    : m_srcRect(srcRect),
    m_duration(duration)
{
}

const RECT& SpriteFrame::GetSrcRect() const
{
    return m_srcRect;
}

float SpriteFrame::GetDuration() const
{
    return m_duration;
}