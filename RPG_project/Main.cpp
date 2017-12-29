#include "Graphics.h"
#include "GameLoop.h"
#include <iostream>









int main() // Where it all begins
{


	int width = 800, height = 600;
	//std::cin >> width;
//	std::cin >> height;
	std::string WindowName = "GameWindow"; // TODO something with these


	sf::RenderWindow win(sf::VideoMode(width, height), WindowName, sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize); // create window
	win.setFramerateLimit(0); // disables framerate limit
	Graphics gfx(win);
	Game game(win,gfx);


	
	game.Loop();

	return 1; // Exit the program
}