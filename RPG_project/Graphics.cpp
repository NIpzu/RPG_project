#include "Graphics.h"


Graphics::Graphics(sf::RenderWindow& win)
	:
	win(win)
{
}



void Graphics::Draw(sf::Sprite* sprite, sf::Vector2f& pos)
{
	sprite->setPosition(pos);
	win.draw(*sprite);
}

void Graphics::Clear(sf::Color& color)
{
	win.clear(color);
}

void Graphics::Display()
{
	win.display();
}
