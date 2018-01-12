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
	Character character{ {400,300} };

private:
	void UpdateScene();
	void DrawScene() const;
	void ProcessEvents();
	void ProcessKeyPress(const sf::Event& event);



private:
	Graphics& gfx;
	sf::Window& win;
};