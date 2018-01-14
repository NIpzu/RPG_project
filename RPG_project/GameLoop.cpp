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
	dt = clock.restart();
	passed += dt;
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
}

void Game::UpdateScene()
{
	ProcessEvents();
	character.Update(dt.asSeconds());
}

void Game::DrawScene() const
{
	CentralizeToCharacter();
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
		{
			looping = false;
			break;
		}

		case sf::Event::Resized:
		{
			gfx.ReSize(event);
			break;
		}

		case sf::Event::KeyPressed:
		{
			ProcessKeyPress(event);
			break;
		}

		case sf::Event::MouseWheelScrolled:
		{
			int delta = std::round(event.mouseWheelScroll.delta);
			gfx.SetSpriteScale(std::max(gfx.GetSpriteScale() + delta,1));
			break;
		}

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
	{
		looping = false;
		break;
	}
	
	default:
		break;
	}
}

void Game::CentralizeToCharacter() const
{
	sf::View newView = gfx.GetView();
	newView.setCenter(character.GetPos() + (sf::Vector2f(settings.GetSpriteSizeXScale()) / 2.0f));
	gfx.SetView(newView);
}
