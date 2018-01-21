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

	void DrawSpriteToTex(const sf::Texture& texture, const sf::Vector2f& pos, sf::RenderTarget& target) const;
	void DrawSpriteToTex(const int index, const sf::Vector2f& pos, sf::RenderTarget& target) const;

	void Clear(const sf::Color& color = sf::Color(0, 0, 0)) const;
	void Display() const;

	void SetView(const sf::View view) const;
	const sf::View& GetView() const;
	void ReSize(const sf::Event& event) const;
	sf::Vector2u GetWindowSize() const;




	void DrawPoint(const sf::Vector2f& pos) const;
private:
	sf::RenderWindow& win;
	TextureList textureList;
};
