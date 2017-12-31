#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Settings.h"

class TextureList
{
public:
	TextureList(const Settings& settings);
	TextureList() = delete;
	void Load(const int index);
	void Free(const int index);
	void LoadAll();
	const sf::Texture& GetTexture(const int index) const;
	const sf::Texture& LoadAndGetTexture(const int index);
private:
	const int spriteWidth, spriteHeight, nRows, nColumns;
	const std::string filename;
	std::vector<int> indexToVector;
	std::vector<sf::Texture> textureArray;
};