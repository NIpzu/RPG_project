#include "GameLoop.h"

Game::Game(sf::Window& win, Graphics& gfx, const Settings& settings)
	:
	win(win),
	gfx(gfx),
	map(settings,gfx)
{
}

void Game::LoopOnce()
{
	passed += clock.restart();
	++updates;

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
	std::cout << "Average frametime:" << float(updates) / passed.asSeconds();
	sf::sleep(sf::seconds(1));
	//std::cin.clear();
	//std::cin.get();
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
			if (event.key.code == sf::Keyboard::Left)
			{
				sf::View view = gfx.GetView();
				view.move(-10, 0);
				gfx.SetView(view);
			}
			if (event.key.code == sf::Keyboard::Right)
			{
				sf::View view = gfx.GetView();
				view.move(10, 0);
				gfx.SetView(view);

			}
			if (event.key.code == sf::Keyboard::Up)
			{
				sf::View view = gfx.GetView();
				view.move(0, -10);
				gfx.SetView(view);

			}
			if (event.key.code == sf::Keyboard::Down)
			{
				sf::View view = gfx.GetView();
				view.move(0, 10);
				gfx.SetView(view);

			}
		}
		if (event.type == sf::Event::Resized)
		{
			sf::FloatRect visibleArea(0.0f, 0.0f, (float)event.size.width, (float)event.size.height);
			sf::View view(visibleArea);
			gfx.SetView(view);
		}
	}



}

void Game::DrawScene()
{
	map.Draw(gfx);
}
