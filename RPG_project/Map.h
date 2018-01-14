#pragma once

#include <string>
#include <vector>
#include "TileTypes.h"
#include "Settings.h"
#include "Graphics.h"

class Map
{
public:
	Map(const Settings& settings, const Graphics& gfx);
	void Draw(const Graphics& gfx) const;
private:
	std::vector<TileTypes> mapVec;

private:
	bool BlocksMovement(const TileTypes type) const
	{
		return !DoesNotBlockMovement(type);
	}
	bool DoesNotBlockMovement(const TileTypes type) const
	{
		return char(type) >= 0b1000000;
	}
	sf::RenderTexture tex;
private:
	int mapWidth;
	int mapHeight;
	int spriteWidth;
	int spriteHeight;
};