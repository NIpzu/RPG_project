#pragma once

#include <SFML\Graphics.hpp>
#include <string>

class Graphics
{
public:
	Graphics(sf::RenderWindow& win);
	void DrawSprite(sf::Sprite* sprite, sf::Vector2f& pos);
	void Clear(sf::Color& color = sf::Color(0, 0, 0));
	void Display();



private:
	sf::RenderWindow& win;
};
