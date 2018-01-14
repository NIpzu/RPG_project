#include "Graphics.h"
#include "GameLoop.h"
#include <iostream>
#include "Settings.h"








int main() // Where it all begins
{



	Settings settings("settings.txt");

	sf::RenderWindow win(sf::VideoMode(settings.GetWindowSize().x, settings.GetWindowSize().y), settings.GetWindowName(), sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize,sf::ContextSettings(0)); // create window
	win.setFramerateLimit(0); // disables framerate limit
	win.setVerticalSyncEnabled(false); 
	win.setMouseCursorVisible(false);
	Graphics gfx(win,settings);
	Game game(win, gfx, settings);
	
	game.Loop();

	return 1; // Exit the program
}