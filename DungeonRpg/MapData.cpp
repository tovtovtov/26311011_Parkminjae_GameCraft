
#include "MapData.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

bool MapData::LoadCSV(const std::string& path)
{
    std::ifstream file(path);

    if (!file.is_open())
    {
        std::cerr << "Failed to open map CSV: " << path << '\n';
        return false;
    }

    m_tiles.clear();

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream stream(line);
        std::string value;

        std::vector<int> row;

        while (std::getline(stream, value, ','))
        {
            // Windows CSV의 줄 끝에 남을 수 있는 공백 제거
            size_t start = value.find_first_not_of(" \t\r\n");
            size_t end = value.find_last_not_of(" \t\r\n");

            if (start == std::string::npos)
                continue;

            value = value.substr(start, end - start + 1);

            try
            {
                row.push_back(std::stoi(value));
            }
            catch (...)
            {
                std::cerr << "Invalid tile ID in CSV\n";
                return false;
            }
        }

        if (!row.empty())
            m_tiles.push_back(row);
    }

    file.close();

    if (m_tiles.empty())
        return false;

    m_height = static_cast<int>(m_tiles.size());
    m_width = static_cast<int>(m_tiles[0].size());

    // 모든 행의 타일 개수가 같은지 검사
    for (const auto& row : m_tiles)
    {
        if (static_cast<int>(row.size()) != m_width)
        {
            std::cerr << "Invalid map row width\n";
            m_tiles.clear();
            m_width = 0;
            m_height = 0;
            return false;
        }
    }

    std::cout << "Map loaded: "
        << m_width << " x " << m_height << '\n';

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
