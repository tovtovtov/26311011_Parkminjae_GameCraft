
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

    if (textureWidth <= 0 || textureHeight <= 0)
    {
        m_tileColumns = 0;
        m_tileRows = 0;
        return;
    }

    int tileSize = mapData->GetTileSize();

    m_tileColumns = textureWidth / tileSize;
    m_tileRows = textureHeight / tileSize;
}

void MapRenderer::Render()
{
    if (!m_mapData || m_textureKey < 0)
        return;

    if (m_tileColumns <= 0 || m_tileRows <= 0)
        return;

    int tileSize = m_mapData->GetTileSize();

    for (int y = 0; y < m_mapData->GetHeight(); ++y)
    {
        for (int x = 0; x < m_mapData->GetWidth(); ++x)
        {
            int tileID = m_mapData->GetTile(x, y);

            // -1은 출력하지 않음
            if (tileID < 0)
                continue;

            // 텍스처 범위 검사
            if (tileID >= m_tileColumns * m_tileRows)
                continue;

            // PNG 내부 타일 좌표
            int srcX = (tileID % m_tileColumns) * tileSize;
            int srcY = (tileID / m_tileColumns) * tileSize;

            RECT srcRect =
            {
                srcX,
                srcY,
                srcX + tileSize,
                srcY + tileSize
            };

            // 게임 월드 좌표
            VEC2 position =
            {
                static_cast<float>(x * tileSize),
                static_cast<float>(y * tileSize)
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
