#include "SoundManager.h"
#include "glc2d.h"

SoundManager::~SoundManager()
{
    ReleaseAll();
}

int SoundManager::Load(
    const std::string& name,
    const std::string& path)
{
    auto iter = m_sounds.find(name);

    if (iter != m_sounds.end())
    {
        return iter->second;
    }

    int soundKey = g2_SoundLoad(path.c_str());

    if (soundKey < 0)
    {
        return -1;
    }

    m_sounds[name] = soundKey;

    return soundKey;
}

int SoundManager::Get(const std::string& name) const
{
    auto iter = m_sounds.find(name);

    if (iter == m_sounds.end())
    {
        return -1;
    }

    return iter->second;
}

void SoundManager::Play(const std::string& name, bool loop)
{
    int soundKey = Get(name);

    if (soundKey < 0)
    {
        return;
    }

    g2_SoundPlay(soundKey, loop);
}

void SoundManager::Stop(const std::string& name)
{
    int soundKey = Get(name);

    if (soundKey < 0)
    {
        return;
    }

    g2_SoundStop(soundKey);
}

void SoundManager::ReleaseAll()
{
    for (const auto& sound : m_sounds)
    {
        g2_SoundRelease(sound.second);
    }

    m_sounds.clear();
}