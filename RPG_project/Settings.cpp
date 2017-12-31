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
		else if (str == "[SpriteScale]")
		{
			file >> spriteScale;
		}
		else if (str == "[WindowSize]")
		{
			file >> windowSize.x >> windowSize.y;
		}
		else if (str == "[WindowName]")
		{
			file >> windowName;
		}
	}
	if (!file.eof())
		std::cout << "Error in settings file! File name: " << filename << std::endl;
}

sf::Vector2u Settings::GetSpriteSize() const
{
	return spriteSize;
}

int Settings::GetSpriteWidth() const
{
	return spriteSize.x;
}

int Settings::GetSpriteHeight() const
{
	return spriteSize.y;
}

sf::Vector2u Settings::GetSpriteFileSize() const
{
	return spriteFileSize;
}

int Settings::GetSpriteFileWidth() const
{
	return spriteFileSize.x;
}

int Settings::GetSpriteFileHeight() const
{
	return spriteFileSize.y;
}

sf::Vector2u Settings::GetWindowSize() const
{
	return windowSize;
}

int Settings::GetWindowWidth() const
{
	return windowSize.x;
}

int Settings::GetWindowHeight() const
{
	return windowSize.y;
}

int Settings::GetSpriteScale() const
{
	return spriteScale;
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
