#pragma once

#include <string>
#include <unordered_map>

class SoundManager
{
private:
    std::unordered_map<std::string, int> m_sounds;

public:
    ~SoundManager();

    int Load(const std::string& name, const std::string& path);

    int Get(const std::string& name) const;

    void Play(const std::string& name, bool loop = false);

    void Stop(const std::string& name);

    void ReleaseAll();
};