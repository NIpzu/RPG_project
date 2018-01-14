#include "Settings.h"
#include <fstream>
#include <iostream>

Settings::Settings(const std::string& filename)
{
	std::ifstream file(filename);



	while (file.good())
	{
		std::string str;
		file >> str;
		if (str == "[SpriteFileName]")
		{
			file >> spriteFileName;
		}
		else if (str == "[SpriteFileSize]")
		{
			file >> spriteFileSize.x >> spriteFileSize.y;
		}
		else if (str == "[SpriteSize]")
		{
			file >> spriteSize.x >> spriteSize.y;
		}
		else if (str == "[WindowSize]")
		{
			file >> windowSize.x >> windowSize.y;
		}
		else if (str == "[WindowName]")
		{
			file >> windowName;
		}
		else if (str == "[MapFileName]")
		{
			file >> mapFileName;
		}
	}
	if (!file.eof())
		std::cout << "Error in settings file! File name: " << filename << std::endl;

	sf::Vector2u(spriteSize.x , spriteSize.y);
}

sf::Vector2u Settings::GetSpriteSize() const
{
	return spriteSize;
}

sf::Vector2u Settings::GetSpriteFileSize() const
{
	return spriteFileSize;
}

sf::Vector2u Settings::GetWindowSize() const
{
	return windowSize;
}

std::string Settings::GetSpriteFileName() const
{
	return spriteFileName;
}

std::string Settings::GetMapFileName() const
{
	return mapFileName;
}

std::string Settings::GetWindowName() const
{
	return windowName;
}
