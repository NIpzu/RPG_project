#pragma once

#include <string>
#include <vector>
#include "Settings.h"
#include "Graphics.h"

class Map
{
public:
	Map(const Settings& settings, const Graphics& gfx);
	void Draw(const Graphics& gfx) const;
private:
	std::vector<unsigned char> mapVec;

private:
	int mapWidth;
	int mapHeight;
	sf::Texture spriteSheet;
	sf::RenderTexture tex;
	sf::VertexArray sprite;
};