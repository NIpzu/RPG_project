#pragma once

#include <SFML\Graphics.hpp>
#include <string>
#include "TextureList.h"
#include "Settings.h"

class Graphics
{
public:
	Graphics(sf::RenderWindow& win, const Settings& settings);

public:
	void DrawSprite(const sf::Texture& texture, const sf::Vector2f& pos) const;
	void DrawSprite(const int index, const sf::Vector2f& pos) const;

	void Clear(const sf::Color& color = sf::Color(0, 0, 0)) const;
	void Display() const;

	void SetView(const sf::View view) const;
	const sf::View& GetView() const;


private:
	sf::RenderWindow& win;
	TextureList textureList;
	int spriteScale;
};
