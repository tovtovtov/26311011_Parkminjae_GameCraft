#pragma once

#include <string>
#include <unordered_map>
#include "AnimationClip.h"
#include <utility>

class AnimationManager
{
private:
    std::unordered_map<std::string, AnimationClip> m_animations;

public:
    ~AnimationManager();

    bool AddFromRow(
        const std::string& name,
        int textureKey,
        int row,
        int frameCount,
        float frameDuration,
        int width,
        int height
    );

    const AnimationClip* Get(const std::string& name) const;

    void ReleaseAll();
};