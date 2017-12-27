#include "Graphics.h"
#include "GameLoop.h"
#include <iostream>









int main() // Where it all begins
{


	int width = 800, height = 600;
	std::string WindowName = "GameWindow"; // TODO something with these


	sf::RenderWindow win(sf::VideoMode(width, height), WindowName); // create window
	win.setFramerateLimit(0); // disables framerate limit

	Game game(win,Graphics(win));

	std::cout << sizeof(Game);

	
	game.Loop();

	return 1; // Exit the program
}