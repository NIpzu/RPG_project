#pragma once
#include <string>
#include <SFML\System.hpp>

class Settings
{
public:
	Settings(const std::string& filename);
	Settings() = delete;
	sf::Vector2u GetSpriteSize() const;
	int GetSpriteWidth() const;
	int GetSpriteHeight() const;
	sf::Vector2u GetSpriteFileSize() const;
	int GetSpriteFileWidth() const;
	int GetSpriteFileHeight() const;
	sf::Vector2u GetWindowSize() const;
	int GetWindowWidth() const;
	int GetWindowHeight() const;
	int GetSpriteScale() const;
	std::string GetSpriteFileName() const;
	std::string GetMapFileName() const;
	std::string GetWindowName() const;
private:
	sf::Vector2u spriteSize = { 32,32 };
	sf::Vector2u spriteFileSize = { 3,2 };
	sf::Vector2u windowSize = { 800,600 };
	std::string spriteFileName = "Sprites.png";
	std::string mapFileName = "Map.dat";
	std::string windowName = "GameWindow";
	int spriteScale = 1;
};