#include "Graphics.h"
#include "GameLoop.h"
#include <iostream>
#include "Settings.h"








int main() // Where it all begins
{



	Settings settings("settings.txt");

	sf::RenderWindow win(sf::VideoMode(settings.GetWindowWidth(), settings.GetWindowHeight()), settings.GetWindowName(), sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize); // create window
	win.setFramerateLimit(0); // disables framerate limit
	win.setVerticalSyncEnabled(false);
	Graphics gfx(win,settings);
	Game game(win, gfx, settings);


	
	game.Loop();

	return 1; // Exit the program
}