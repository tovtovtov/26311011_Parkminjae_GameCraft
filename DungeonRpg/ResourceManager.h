#pragma once

#include "TextureManager.h"
#include "SoundManager.h"
#include "AnimationManager.h"

class ResourceManager
{
private:
    TextureManager m_textureManager;
    SoundManager m_soundManager;
    AnimationManager m_animationManager;

public:
    TextureManager& GetTextureManager();
    SoundManager& GetSoundManager();
    AnimationManager& GetAnimationManager();

    void ReleaseAll();
};
