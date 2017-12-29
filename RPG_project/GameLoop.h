#pragma once

#include "Graphics.h"
#include "TextureList.h"
#include "Character.h"

class Game
{
public:
	Game(sf::Window& win, Graphics& gfx);
	void LoopOnce();
	void Loop();


private:
	bool looping = false;

	Character character{ sf::Vector2f(100,100) };

private:
	void UpdateScene();
	void DrawScene();



private:
	Graphics& gfx;
	sf::Window& win;
};