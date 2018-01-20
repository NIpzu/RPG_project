#include "GameWindow.h"

GameWindow::GameWindow(std::string settingsFile)
	:
	settings(settingsFile),
	win(sf::VideoMode(settings.GetWindowSize().x, settings.GetWindowSize().y), settings.GetWindowName(), sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize, sf::ContextSettings(0)),
	gfx(win,settings),
	gameloop(win,gfx,settings)
{
}

void GameWindow::StartGame()
{
	gameloop.Loop();
}
