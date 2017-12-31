#include "TextureList.h"

TextureList::TextureList(const Settings& settings)
	:
	spriteWidth(settings.GetSpriteWidth()),
	spriteHeight(settings.GetSpriteHeight()),
	nColumns(3 * 32/ spriteWidth),
	nRows(2 * 32 / spriteWidth),
	filename(settings.GetSpriteFileName()),
	indexToVector(nRows * nColumns, -1)
{
}

void TextureList::Load(const int index)
{
	if (indexToVector[index] == -1)
	{
		textureArray.emplace_back();
		indexToVector[index] = (int)textureArray.size() - 1;
		textureArray[indexToVector[index]].loadFromFile(filename, sf::IntRect(spriteWidth * (index % nColumns), spriteHeight * (index / nColumns), spriteWidth, spriteHeight));
	}
}

void TextureList::Free(const int index)
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

void TextureList::LoadAll()
{
	for (int i = 0; i < indexToVector.size(); i++)
	{
		Load(i);
	}
}

const sf::Texture& TextureList::GetTexture(const int index) const
{
	return textureArray[indexToVector[index]];
}

const sf::Texture& TextureList::LoadAndGetTexture(const int index)
{
	Load(index);
	return GetTexture(index);
}
