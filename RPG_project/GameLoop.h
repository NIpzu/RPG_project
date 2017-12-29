#pragma once

#include "Graphics.h"
#include "Character.h"

class Game
{
public:
	Game(sf::Window& win, Graphics& gfx);
	void LoopOnce();
	void Loop();


private:
	bool looping = false;

	Character character{ sf::Vector2f(300,200) };

private:
	void UpdateScene();
	void DrawScene();



private:
	Graphics& gfx;
	sf::Window& win;
};