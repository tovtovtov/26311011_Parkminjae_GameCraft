
#pragma once

#include <string>
#include <vector>

class MapData
{
private:
    int m_width = 0;
    int m_height = 0;
    int m_tileSize = 32;

    std::vector<std::vector<int>> m_tiles;

public:
    bool LoadCSV(const std::string& path);

    int GetTile(int x, int y) const;

    int GetWidth() const;
    int GetHeight() const;
    int GetTileSize() const;
};
