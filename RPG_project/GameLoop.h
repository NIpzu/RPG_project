#pragma once

#include "Graphics.h"


class Game
{
public:
	Game(sf::Window& win, Graphics& gfx);
	void LoopOnce();
	void Loop();


private:
	bool looping = false;



private:
	void UpdateScene();
	void DrawScene();




private:
	Graphics& gfx;
	sf::Window& win;
};