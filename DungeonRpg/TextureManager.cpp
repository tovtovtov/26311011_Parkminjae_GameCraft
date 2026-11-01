#include "TextureManager.h"
#include "glc2d.h"

TextureManager::~TextureManager()
{
    ReleaseAll();
}

int TextureManager::Load(
    const std::string& name,
    const std::string& path)
{
    // 이미 등록된 리소스라면 기존 번호 반환
    auto iter = m_textures.find(name);

    if (iter != m_textures.end())
    {
        return iter->second;
    }

    // 엔진을 이용해 이미지 로딩
    int textureKey = g2_TextureLoad(path.c_str());

    if (textureKey < 0)
    {
        return -1;
    }

    m_textures[name] = textureKey;

    return textureKey;
}

int TextureManager::Get(const std::string& name) const
{
    auto iter = m_textures.find(name);

    if (iter == m_textures.end())
    {
        return -1;
    }

    return iter->second;
}

void TextureManager::ReleaseAll()
{
    for (const auto& texture : m_textures)
    {
        g2_TextureRelease(texture.second);
    }

    m_textures.clear();
}
