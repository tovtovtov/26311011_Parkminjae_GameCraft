
#include "MapData.h"

#include <fstream>
#include <sstream>
#include <iostream>

bool MapData::LoadCSV(const std::string& path)
{
    std::ifstream file(path);

    if (!file.is_open())
    {
        std::cerr << "Failed to open CSV: "
            << path << '\n';
        return false;
    }

    std::vector<std::vector<int>> newTiles;

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream stream(line);
        std::string value;

        std::vector<int> row;

        while (std::getline(stream, value, ','))
        {
            size_t start =
                value.find_first_not_of(" \t\r\n");

            size_t end =
                value.find_last_not_of(" \t\r\n");

            if (start == std::string::npos)
                continue;

            value = value.substr(
                start,
                end - start + 1
            );

            try
            {
                row.push_back(std::stoi(value));
            }
            catch (...)
            {
                std::cerr << "Invalid tile ID\n";
                return false;
            }
        }

        if (!row.empty())
            newTiles.push_back(row);
    }

    if (newTiles.empty())
        return false;

    int width = static_cast<int>(
        newTiles[0].size()
        );

    for (const auto& row : newTiles)
    {
        if (static_cast<int>(row.size()) != width)
        {
            std::cerr << "Invalid CSV row width\n";
            return false;
        }
    }

    m_tiles = std::move(newTiles);

    m_width = width;
    m_height = static_cast<int>(m_tiles.size());

    std::cout << "Map loaded: "
        << m_width << " x "
        << m_height << '\n';

    return true;
}

int MapData::GetTile(int x, int y) const
{
    if (x < 0 || y < 0 ||
        x >= m_width || y >= m_height)
    {
        return -1;
    }

    return m_tiles[y][x];
}

int MapData::GetWidth() const
{
    return m_width;
}

int MapData::GetHeight() const
{
    return m_height;
}

int MapData::GetTileSize() const
{
    return m_tileSize;
}
