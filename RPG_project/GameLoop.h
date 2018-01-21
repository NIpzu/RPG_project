#pragma once

#include "Graphics.h"
#include "Character.h"
#include "Map.h"

class GameLoop
{
public:
	GameLoop(sf::Window& win, Graphics& gfx, const Settings& settings);
	void LoopOnce();
	void Loop();


private:
	bool looping = false;
	sf::Time dt;
	sf::Time passed;
	sf::Clock clock;
	int updates = 0;
	Map map;
	Character character{ {0,0} };

	float screenScale = 1;
private:
	void UpdateScene();
	void DrawScene() const;
	void ProcessEvents();
	void ProcessKeyPress(const sf::Event& event);
	void CentralizeToCharacter() const;

	int counter = 0;
private:
	Graphics& gfx;
	sf::Window& win;
	const Settings& settings;
};