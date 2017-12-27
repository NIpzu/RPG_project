#pragma once

#include "Graphics.h"
#include "TextureList.h"


class Game
{
public:
	Game(sf::Window& win, Graphics& gfx);
	void LoopOnce();
	void Loop();


private:
	bool looping = false;

	TextureList spl;


private:
	void UpdateScene();
	void DrawScene();



private:
	Graphics& gfx;
	sf::Window& win;
};