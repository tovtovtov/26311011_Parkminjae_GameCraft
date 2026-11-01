#include "ResourceManager.h"

TextureManager& ResourceManager::GetTextureManager()
{
    return m_textureManager;
}

SoundManager& ResourceManager::GetSoundManager()
{
    return m_soundManager;
}

AnimationManager& ResourceManager::GetAnimationManager()
{
    return m_animationManager;
}

void ResourceManager::ReleaseAll()
{
    m_animationManager.ReleaseAll();
    m_textureManager.ReleaseAll();
    m_soundManager.ReleaseAll();
}