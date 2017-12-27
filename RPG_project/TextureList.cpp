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
		TextureArray.emplace_back(*texture);
		indexToVector[index] = TextureArray.size() - 1;
	}
}

void TextureList::Free(int index)
{
	if (indexToVector[index] != -1)
	{

	}
}

sf::Texture* TextureList::getTexture(int index)
{
	return &TextureArray[indexToVector[index]];
}
