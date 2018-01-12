#include "Map.h"
#include <iostream>
#include "FileAcces.h"
#include <cmath>
#include <algorithm>

Map::Map(const Settings& settings, const Graphics& gfx)
	:
	spriteScale(settings.GetSpriteScale()),
	spriteWidth(settings.GetSpriteWidth()),
	spriteHeight(settings.GetSpriteHeight())
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
		//tex.setView(sf::View(sf::Rect<float>(0, 0, spriteScale * spriteWidth, spriteScale * spriteHeight)));

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

void Map::Draw(const Graphics& gfx)
{
	/*sf::Vector2f center = gfx.GetView().getCenter();
	int centerToCorner = int(std::sqrt(std::pow(gfx.GetView().getSize().x / 2, 2) + std::pow(gfx.GetView().getSize().y / 2, 2)));
	for (int x = std::max((int(center.x) - centerToCorner) / (spriteScale * spriteWidth),0); x <= std::min((int(center.x) + centerToCorner) / (spriteScale * spriteWidth), int(mapWidth) - 1); x++)
	{
		for (int y = std::max((int(center.y) - centerToCorner) / (spriteScale * spriteHeight),0); y <= std::min((int(center.y) + centerToCorner) / (spriteScale * spriteHeight),mapHeight - 1); y++)
		{
			gfx.DrawSprite((char)mapVec[y * mapWidth + x], sf::Vector2f(float(x * spriteScale * spriteWidth),float( y * spriteScale * spriteHeight)));
		}
	}*/
	gfx.DrawSprite(tex.getTexture(), sf::Vector2f( 0.0f,0.0f ));
}