#include "GameLoop.h"

Game::Game(sf::Window& win, Graphics& gfx, const Settings& settings)
	:
	win(win),
	gfx(gfx),
	map(settings,gfx),
	settings(settings)
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
	ProcessEvents();

}

void Game::DrawScene() const
{
	map.Draw(gfx);
	character.Draw(gfx,settings);
}

void Game::ProcessEvents()
{
	sf::Event event;
	while (win.pollEvent(event))
	{
		switch (event.type)
		{

		case sf::Event::Closed:
			looping = false;
			break;

		case sf::Event::Resized:
		{
			gfx.ReSize(event);
			break;
		}

		case sf::Event::KeyPressed:

			break;


		default:
			break;
		}

	}
}

void Game::ProcessKeyPress(const sf::Event & event)
{
	switch (event.key.code)
	{
	case sf::Keyboard::Escape:
		looping = false;
		break;
	default:
		break;
	}
}
