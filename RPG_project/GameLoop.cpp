#include "GameLoop.h"

Game::Game(sf::Window& win, Graphics& gfx)
	:
	win(win),
	gfx(gfx)
{
}

void Game::LoopOnce()
{
	gfx.Clear(sf::Color(69,69,69)/* Insert background color */);

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
		if (event.type == sf::Event::Resized)
		{
			// update the view to the new size of the window
			sf::FloatRect visibleArea(0.0f, 0.0f, (float)event.size.width, (float)event.size.height);
			gfx.setView(sf::View(visibleArea));
		}
	}




}

void Game::DrawScene()
{
	character.Draw(gfx);
}
