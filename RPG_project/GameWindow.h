#pragma once

#include <SFML\Graphics.hpp>
#include "GameLoop.h"

class GameWindow
{
public:
	GameWindow(std::string settingsFile);
	void StartGame();
private:
	Settings settings;
	sf::RenderWindow win;
	Graphics gfx;
	GameLoop gameloop;
};