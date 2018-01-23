#include "Map.h"
#include <iostream>
#include <cmath>
#include <algorithm>

Map::Map(const Settings& settings, const Graphics& gfx)
	:
	sprite(sf::Quads, 4)
{


	const int spriteWidth = settings.GetSpriteSize().x;
	const int spriteHeight = settings.GetSpriteSize().y;

	sf::FileInputStream file;
	file.open(settings.GetMapFileName());

	spriteSheet.loadFromFile(settings.GetMapSpriteFileName());

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

		mapHeight = (int(mapVec[mapVec.size() - 2]) << 8) | mapVec[mapVec.size() - 1];
		mapVec.pop_back();
		mapVec.pop_back();

		mapWidth = (int(mapVec[mapVec.size() - 2]) << 8) | mapVec[mapVec.size() - 1];
		mapVec.pop_back();
		mapVec.pop_back();


		if (mapVec.size() % mapWidth != 0)
		{
			std::cout << "There were excess bytes in the map file!" << std::endl;
		}
		tex.create(spriteWidth * mapWidth, spriteHeight * mapHeight);


		sf::VertexArray vArray(sf::Quads, 4 * mapWidth * mapHeight);

		sf::Clock timer;
		timer.restart();
		for (int x = 0; x < mapWidth; x++)
		{
			for (int y = 0; y < mapHeight; y++)
			{
				const sf::Vector2f pos = sf::Vector2f(float(x * spriteWidth), float(y * spriteHeight));
				vArray[4 * (y * mapWidth + x)].position = pos;
				vArray[4 * (y * mapWidth + x) + 1].position = pos + sf::Vector2f((float)spriteWidth, 0.0f);
				vArray[4 * (y * mapWidth + x) + 2].position = pos + sf::Vector2f((float)spriteWidth, (float)spriteHeight);
				vArray[4 * (y * mapWidth + x) + 3].position = pos + sf::Vector2f(0.0f, (float)spriteHeight);


				const sf::Vector2f texPos = sf::Vector2f(float(mapVec[y * mapWidth + x] % mapWidth * spriteWidth),float( mapVec[y * mapWidth + x] / mapWidth * spriteHeight));
				vArray[4 * (y * mapWidth + x)].texCoords = texPos;
				vArray[4 * (y * mapWidth + x) + 1].texCoords = texPos + sf::Vector2f((float)spriteWidth, 0.0f);
				vArray[4 * (y * mapWidth + x) + 2].texCoords = texPos + sf::Vector2f((float)spriteWidth, (float)spriteHeight);
				vArray[4 * (y * mapWidth + x) + 3].texCoords = texPos + sf::Vector2f(0.0f, (float)spriteHeight);
			}
		}
		tex.draw(vArray,&spriteSheet);
		tex.display();
		std::cout << timer.restart().asMicroseconds() << std::endl;

	}
	else
	{
		std::cout << "Can not find file " << settings.GetMapFileName() << "!" << std::endl;
	}

	sprite[0].position = sf::Vector2f(0.0f, 0.0f);
	sprite[1].position = sf::Vector2f(float(mapWidth * gfx.GetSpriteSize().x), 0.0f);
	sprite[2].position = sf::Vector2f(float(mapWidth * gfx.GetSpriteSize().x), float(mapHeight * gfx.GetSpriteSize().y));
	sprite[3].position = sf::Vector2f(0.0f, float(mapHeight * gfx.GetSpriteSize().y));

	sprite[0].texCoords = sf::Vector2f(0.0f, 0.0f);
	sprite[1].texCoords = sf::Vector2f((float)tex.getTexture().getSize().x, 0.0f);
	sprite[2].texCoords = sf::Vector2f((float)tex.getTexture().getSize().x, (float)tex.getTexture().getSize().y);
	sprite[3].texCoords = sf::Vector2f(0.0f, (float)tex.getTexture().getSize().y);
}

void Map::Draw(const Graphics& gfx) const
{
	gfx.GetRenderTarget().draw(sprite, &tex.getTexture());
}