#include "GameLoop.h"

GameLoop::GameLoop(sf::Window& win, Graphics& gfx, const Settings& settings)
	:
	win(win),
	gfx(gfx),
	map(settings,gfx),
	settings(settings)
{
}

void GameLoop::LoopOnce()
{
	dt = clock.restart();
	passed += dt;
	++updates;

	gfx.Clear(sf::Color(69,69,69));

	UpdateScene();

	DrawScene();

	gfx.Display();
}

void GameLoop::Loop()
{
	looping = true;
	while (looping)
	{
		LoopOnce();
	}
	std::cout << "Average frames per second: " << float(updates) / passed.asSeconds() << " fps" << std::endl;
	std::cout << "Average frametime: " << passed.asSeconds() / float(updates) * 1000 << " ms" << std::endl;
	sf::sleep(sf::seconds(1));
}

void GameLoop::UpdateScene()
{
	ProcessEvents();
	character.Update(dt.asSeconds());
}

void GameLoop::DrawScene() const
{
	CentralizeToCharacter();
	map.Draw(gfx);
	character.Draw(gfx,settings);
}

void GameLoop::ProcessEvents()
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
			CentralizeToCharacter();
			break;
		}

		case sf::Event::KeyPressed:
		{
			ProcessKeyPress(event);
			break;
		}

		case sf::Event::MouseWheelScrolled:
		{
			sf::View newView(gfx.GetView());
			if (std::round(event.mouseWheelScroll.delta) < 0)
			{
				screenScale--;
			//newView.setSize(newView.getSize() / 0.5f);
			}
			if (std::round(event.mouseWheelScroll.delta) > 0)
			{
				screenScale++;
				//newView.setSize(newView.getSize() / 2.0f);
			}
			newView.setSize(sf::Vector2f(gfx.GetWindowSize()) / screenScale);
			gfx.SetView(newView);
			break;
		}

		default:
			break;
		}

	}
}

void GameLoop::ProcessKeyPress(const sf::Event & event)
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

void GameLoop::CentralizeToCharacter() const
{
	sf::View newView = gfx.GetView();
	newView.setCenter(character.GetPos() + sf::Vector2f(settings.GetSpriteSize()) / 2.0f);
	gfx.SetView(newView);
}
