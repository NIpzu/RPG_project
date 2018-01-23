#include "Graphics.h"

Graphics::Graphics(sf::RenderWindow& win, const Settings& settings)
	:
	win(win),
	//textureList(settings),
	spriteSize(settings.GetSpriteSize())
{
	//textureList.LoadAll();
}
/*
void Graphics::DrawSprite(const sf::Texture& texture, const sf::Vector2f& pos) const
{
	sf::VertexArray quad(sf::Quads, 4);

	const int texWidth = texture.getSize().x;
	const int texHeight = texture.getSize().y;

	quad[0].position = sf::Vector2f(pos.x, pos.y);
	quad[1].position = sf::Vector2f((pos.x + texWidth), pos.y);
	quad[2].position = sf::Vector2f((pos.x + texWidth), (pos.y + texHeight));
	quad[3].position = sf::Vector2f(pos.x, (pos.y + texHeight));

	quad[0].texCoords = sf::Vector2f(0,0);
	quad[1].texCoords = sf::Vector2f(float(texWidth), 0);
	quad[2].texCoords = sf::Vector2f(float(texWidth), float(texHeight));
	quad[3].texCoords = sf::Vector2f(0, float(texHeight));

	win.draw(quad, &texture);
}

void Graphics::DrawSprite(const int index, const sf::Vector2f & pos) const
{
	DrawSprite(textureList.GetTexture(index), pos);
}

void Graphics::DrawSpriteToTex(const sf::Texture& texture, const sf::Vector2f & pos, sf::RenderTarget& target) const
{
	sf::VertexArray quad(sf::Quads, 4);

	const int texWidth = texture.getSize().x;
	const int texHeight = texture.getSize().y;

	quad[0].position = sf::Vector2f(pos.x, pos.y);
	quad[1].position = sf::Vector2f((pos.x + texWidth), pos.y);
	quad[2].position = sf::Vector2f((pos.x + texWidth), (pos.y + texHeight));
	quad[3].position = sf::Vector2f(pos.x, (pos.y + texHeight));

	quad[0].texCoords = sf::Vector2f(0, 0);
	quad[1].texCoords = sf::Vector2f(float(texWidth), 0);
	quad[2].texCoords = sf::Vector2f(float(texWidth), float(texHeight));
	quad[3].texCoords = sf::Vector2f(0, float(texHeight));

	target.draw(quad, &texture);
}

void Graphics::DrawSpriteToTex(const int index, const sf::Vector2f & pos, sf::RenderTarget& target) const
{
	DrawSpriteToTex(textureList.GetTexture(index), pos, target);
}
*/
void Graphics::Clear(const sf::Color& color) const
{
	win.clear(color);
}

void Graphics::Display() const
{
	win.display();
}

void Graphics::SetView(const sf::View view) const
{
	win.setView(view);
}

const sf::View& Graphics::GetView() const
{
	return win.getView();
}

void Graphics::ReSize(const sf::Event & event) const
{
	sf::View newView = win.getView();
	newView.setSize(sf::Vector2f(float(event.size.width), float(event.size.height)));
	win.setView(newView);
}

sf::Vector2u Graphics::GetWindowSize() const
{
	return win.getSize();
}

sf::Vector2u Graphics::GetSpriteSize() const
{
	return spriteSize;
}

sf::RenderTarget& Graphics::GetRenderTarget() const
{
	return win;
}

void Graphics::DrawPoint(const sf::Vector2f & pos) const
{
	sf::VertexArray point(sf::Points, 1);
	point[0].position = pos;
	win.draw(point);
}
