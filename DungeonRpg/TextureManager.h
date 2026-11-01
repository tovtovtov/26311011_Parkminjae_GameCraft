#pragma once

#include <string>
#include <unordered_map>

class TextureManager
{
private:
    // 리소스 이름과 엔진에서 반환한 텍스처 번호
    std::unordered_map<std::string, int> m_textures;

public:
    ~TextureManager();

    // 텍스처 로딩
    int Load(const std::string& name, const std::string& path);

    // 텍스처 번호 반환
    int Get(const std::string& name) const;

    // 모든 텍스처 해제
    void ReleaseAll();
};