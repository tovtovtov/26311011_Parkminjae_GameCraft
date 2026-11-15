#include "MapRenderer.h"
#include "glc2d.h"

void MapRenderer::Init(
    MapData* mapData,
    int textureKey,
    int textureWidth,
    int textureHeight)
{
    m_mapData = mapData;
    m_textureKey = textureKey;

    m_tileColumns = textureWidth / 32;
}

void MapRenderer::Render()
{
    if (!m_mapData || m_textureKey < 0)
        return;

    for (int y = 0; y < m_mapData->GetHeight(); ++y)
    {
        for (int x = 0; x < m_mapData->GetWidth(); ++x)
        {
            int tileID = m_mapData->GetTile(x, y);

            if (tileID < 0)
                continue;

            int srcX = (tileID % m_tileColumns) * 32;
            int srcY = (tileID / m_tileColumns) * 32;

            RECT srcRect =
            {
                srcX,
                srcY,
                srcX + 32,
                srcY + 32
            };

            VEC2 position =
            {
                static_cast<float>(x * 32),
                static_cast<float>(y * 32)
            };

            VEC2 scale = { 1.0f, 1.0f };

            g2_Draw2D(
                m_textureKey,
                &srcRect,
                &position,
                &scale
            );
        }
    }
}