#include "GameLoop.h"

Game::Game(sf::Window& win, Graphics& gfx)
	:
	win(win),
	gfx(gfx),
	spl("test.bmp", 32, 32, 2, 2)
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

	spl.Load(3);
	spl.Load(1);


}

void Game::DrawScene()
{
	gfx.DrawSprite(spl.getTexture(1), sf::Vector2f{1, 2});
	gfx.DrawSprite(spl.getTexture(3), sf::Vector2f{ 121,32 });
}
