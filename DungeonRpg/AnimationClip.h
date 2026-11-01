#pragma once

#include <vector>
#include "SpriteFrame.h"

class AnimationClip
{
private:
    int m_textureKey;
    std::vector<SpriteFrame> m_frames;

public:
    AnimationClip(int textureKey);

    void AddFrame(const SpriteFrame& frame);

    int GetTextureKey() const;
    int GetFrameCount() const;
    const SpriteFrame& GetFrame(int index) const;
};