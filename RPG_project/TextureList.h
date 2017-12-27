#pragma once
#include <string>
#include <vector>
#include <SFML\Graphics.hpp>

class TextureList
{
public:
	TextureList(const std::string& fileName, const int spriteWidth, const int spriteHeight, const int nRows, const int nColumns);
	~TextureList();
	void Load(int index);
	void Free(int index);
	sf::Texture* getTexture(int index);
private:
	const int spriteWidth, spriteHeight, nRows, nColumns;
	const std::string fileName;
	std::vector<int> indexToVector;
	std::vector<sf::Texture> TextureArray;
};