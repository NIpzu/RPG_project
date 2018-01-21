#include "GameWindow.h"

#include <SFML\System\Clock.hpp>
#include <iostream>





int main() // Where it all begins
{
	sf::Clock timer;
	timer.restart();

	GameWindow game("settings.txt"); // Construct window and game logic

	auto passed = timer.restart();
	std::cout << passed.asMilliseconds() << std::endl;

	game.StartGame(); // Start the game loop

	return 1; // Exit the program
}