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
	sf::Time dt;
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
	void CentralizeToCharacter() const;


private:
	Graphics& gfx;
	sf::Window& win;
	const Settings& settings;
};