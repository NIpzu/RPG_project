#include "Graphics.h"


Graphics::Graphics(sf::RenderWindow& win)
	:
	win(win)
{
}

void Graphics::DrawSprite(sf::Sprite* sprite, sf::Vector2f& pos)
{
	sprite->setPosition(pos);
	win.draw(*sprite);
}

void Graphics::DrawSprite(sf::Texture* texture, sf::Vector2f & pos)
{
	sf::Sprite sprite(*texture);
	sprite.setPosition(pos);
	win.draw(sprite);
}

void Graphics::Clear(sf::Color& color)
{
	win.clear(color);
}

void Graphics::Display()
{
	win.display();
}
