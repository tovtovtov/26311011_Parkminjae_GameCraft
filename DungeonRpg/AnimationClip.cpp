#include "AnimationClip.h"

AnimationClip::AnimationClip(int textureKey)
    : m_textureKey(textureKey)
{
}

void AnimationClip::AddFrame(const SpriteFrame& frame)
{
    m_frames.push_back(frame);
}

int AnimationClip::GetTextureKey() const
{
    return m_textureKey;
}

int AnimationClip::GetFrameCount() const
{
    return static_cast<int>(m_frames.size());
}

const SpriteFrame& AnimationClip::GetFrame(int index) const
{
    return m_frames[index];
}