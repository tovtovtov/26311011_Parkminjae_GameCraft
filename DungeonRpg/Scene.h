#pragma once

class Scene
{
public:
    virtual ~Scene() = default;

    // æ¿ √ ±‚»≠
    virtual void Init() = 0;

    // æ¿ æ˜µ•¿Ã∆Æ
    virtual void Update() = 0;

    // æ¿ ∑ª¥ı∏µ
    virtual void Render() = 0;

    // æ¿ ¡æ∑·
    virtual void Destroy() = 0;
};