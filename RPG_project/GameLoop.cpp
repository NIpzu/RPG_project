#include "GameLoop.h"

Game::Game(sf::Window& win, Graphics& gfx)
	:
	win(win),
	gfx(gfx)
{
}

void Game::LoopOnce()
{
	gfx.Clear(/* Insert background color */);

	UpdateScene();

	DrawScene();

	gfx.Display();
}

void Game::Loop()
{
	looping = true;
	while (looping)
	{
		LoopOnce();
	}
}

void Game::UpdateScene()
{
	sf::Event event;
	while (win.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			looping = false;
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				looping = false;
			}
		}
	}
}

void Game::DrawScene()
{
}
