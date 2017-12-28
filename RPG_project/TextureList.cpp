#include "TextureList.h"

TextureList::TextureList(const std::string & fileName, const int spriteWidth, const int spriteHeight, const int nRows, const int nColumns)
	:
	spriteWidth(spriteWidth),
	spriteHeight(spriteHeight),
	nRows(nRows),
	nColumns(nColumns),
	fileName(fileName),
	indexToVector(nRows * nColumns, -1)
{
}

TextureList::~TextureList()
{
}

void TextureList::Load(int index)
{
	if (indexToVector[index] == -1)
	{
		sf::Texture* texture = new sf::Texture;
		texture->loadFromFile(fileName, sf::IntRect(spriteWidth * (index % nColumns), spriteHeight * (index / nColumns), spriteWidth, spriteHeight));
		textureArray.emplace_back(*texture);
		indexToVector[index] = textureArray.size() - 1;
	}
}

void TextureList::Free(int index)
{
	if (indexToVector[index] != -1 && textureArray.size() != 1)
	{
		for (int& i : indexToVector)
		{
			if (i == textureArray.size() - 1)
			{
				i = indexToVector[index];
			}
		}
		std::swap(textureArray[indexToVector[index]], textureArray[textureArray.size() - 1]);
		textureArray.pop_back();
		indexToVector[index] = -1;
	}
}

sf::Texture* TextureList::getTexture(int index)
{
	if (indexToVector[index] == -1)
	{
		Load(index);
	}
	return &textureArray[indexToVector[index]];
}
