#include "GameWindow.h"








int main() // Where it all begins
{
	GameWindow game("settings.txt"); // Construct window and game logic
	game.StartGame(); // Start the game loop

	return 1; // Exit the program
}