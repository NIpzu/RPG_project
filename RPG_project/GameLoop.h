#pragma once

#include "Graphics.h"
#include "Character.h"
#include "Map.h"

class Game
{
public:
	Game(sf::Window& win, Graphics& gfx, const Settings& settings);
	void LoopOnce();
	void Loop();


private:
	bool looping = false;

	sf::Time passed;
	sf::Clock clock;
	int updates = 0;
	Map map;

private:
	void UpdateScene();
	void DrawScene();



private:
	Graphics& gfx;
	sf::Window& win;
};