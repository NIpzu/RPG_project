#include "Map.h"
#include <iostream>
#include "FileAcces.h"
#include <cmath>
#include <algorithm>

Map::Map(const Settings& settings, const Graphics& gfx)
	:
	spriteWidth(settings.GetSpriteSize().x),
	spriteHeight(settings.GetSpriteSize().y)
{

	sf::FileInputStream file;
	file.open(settings.GetMapFileName());

	auto filesize = file.getSize();

	if (filesize != -1)
	{
		mapVec.resize(filesize);

		if (file.read(mapVec.data(), filesize) != filesize)
		{
			std::cout << "Something went wrong while reading from " << settings.GetMapFileName() << "!" << std::endl;
			mapWidth = 0;
			mapHeight = 0;
		}

		mapHeight = (int(mapVec[mapVec.size() - 2]) << 8) | unsigned char(mapVec[mapVec.size() - 1]);
		mapVec.pop_back();
		mapVec.pop_back();

		mapWidth = (int(mapVec[mapVec.size() - 2]) << 8) | unsigned char(mapVec[mapVec.size() - 1]);
		mapVec.pop_back();
		mapVec.pop_back();


		if (mapVec.size() % mapWidth != 0)
		{
			std::cout << "There were excess bytes in the map file!" << std::endl;
		}
		tex.create(spriteWidth * mapWidth, spriteHeight * mapHeight);

		for (int x = 0; x < mapWidth; x++)
		{
			for (int y = 0; y < mapHeight; y++)
			{
				gfx.DrawSpriteToTex((char)mapVec[y * mapWidth + x], sf::Vector2f(float(x * spriteWidth), float(y * spriteHeight)), tex);
			}
		}

		tex.display();

	}
	else
	{
		std::cout << "Can not find file " << settings.GetMapFileName() << "!" << std::endl;
	}


}

void Map::Draw(const Graphics& gfx) const
{
	gfx.DrawSprite(tex.getTexture(), sf::Vector2f( 0.0f,0.0f ));
}