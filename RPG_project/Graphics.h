#pragma once

#include <SFML\Graphics.hpp>
#include <string>
#include "TextureList.h"

class Graphics
{
public:
	Graphics(sf::RenderWindow& win);
	void DrawSprite(sf::Sprite* sprite, const sf::Vector2f& pos);
	void DrawSprite(sf::Texture* texture, const sf::Vector2f& pos);
	void DrawSprite(const int index, const sf::Vector2f& pos);
	void Clear(sf::Color& color = sf::Color(0, 0, 0));
	void Display();

	void setView(sf::View view);


private:
	sf::RenderWindow& win;
	TextureList textureList;
};
