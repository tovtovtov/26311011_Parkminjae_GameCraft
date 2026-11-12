#include "AnimationManager.h"

AnimationManager::~AnimationManager()
{
    ReleaseAll();
}

bool AnimationManager::AddFromRow(
    const std::string& name,
    int textureKey,
    int row,
    int frameCount,
    float frameDuration,
    int width,
    int height)
{
    const int FRAME_WIDTH = width;
    const int FRAME_HEIGHT = height;

    const int SHEET_COLUMNS = 6;
    const int SHEET_ROWS = 16;

    if (textureKey < 0 ||
        row < 0 || row >= SHEET_ROWS ||
        frameCount <= 0 || frameCount > SHEET_COLUMNS ||
        frameDuration <= 0.0f)
    {
        return false;
    }

    if (m_animations.find(name) != m_animations.end())
        return false;

    AnimationClip clip(textureKey);

    for (int i = 0; i < frameCount; ++i)
    {
        RECT rect;

        rect.left = i * FRAME_WIDTH;
        rect.top = row * FRAME_HEIGHT;
        rect.right = rect.left + FRAME_WIDTH;
        rect.bottom = rect.top + FRAME_HEIGHT;

        clip.AddFrame(SpriteFrame(rect, frameDuration));
    }

    m_animations.emplace(name, std::move(clip));

    return true;
}

const AnimationClip* AnimationManager::Get(
    const std::string& name) const
{
    auto iter = m_animations.find(name);

    if (iter == m_animations.end())
        return nullptr;

    return &iter->second;
}

void AnimationManager::ReleaseAll()
{
    m_animations.clear();
}