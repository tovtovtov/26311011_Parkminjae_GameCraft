#pragma once

#include "MapData.h"

class MapRenderer
{
private:
    MapData* m_mapData = nullptr;

    int m_textureKey = -1;
    int m_tileColumns = 0;
    int m_tileRows = 0;

public:
    void Init(
        MapData* mapData,
        int textureKey,
        int textureWidth,
        int textureHeight
    );

    void Render();
};
