#include "Graphics.h"


Graphics::Graphics(sf::RenderWindow& win)
	:
	win(win),
	textureList("test.png",32,32,3,2)
{
}

void Graphics::DrawSprite(sf::Sprite* sprite, const sf::Vector2f& pos)
{
	sprite->setPosition(pos);
	win.draw(*sprite);
}

void Graphics::DrawSprite(sf::Texture* texture, const sf::Vector2f & pos)
{
	sf::VertexArray quad(sf::Quads, 4);

	int sizeMul = 4;
	int texWidth = texture->getSize().x;
	int texHeight = texture->getSize().y;
	int width = texWidth * sizeMul;
	int height = texHeight * sizeMul;

	quad[0].position = pos;
	quad[1].position = sf::Vector2f(pos.x + width, pos.y);
	quad[2].position = sf::Vector2f(pos.x + width, pos.y + height);
	quad[3].position = sf::Vector2f(pos.x, pos.y + height);

	quad[0].texCoords = sf::Vector2f(0,0);
	quad[1].texCoords = sf::Vector2f(float(texWidth), 0);
	quad[2].texCoords = sf::Vector2f(float(texWidth), float(texHeight));
	quad[3].texCoords = sf::Vector2f(0, float(texHeight));

	win.draw(quad, texture);
}

void Graphics::DrawSprite(const int index, const sf::Vector2f & pos)
{
	DrawSprite(textureList.GetTexture(index), pos);
}

void Graphics::Clear(sf::Color& color)
{
	win.clear(color);
}

void Graphics::Display()
{
	win.display();
}

void Graphics::setView(sf::View view)
{
	win.setView(view);
}
