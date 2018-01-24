#include "Character.h"

Character::Character(const sf::Vector2f& pos, const Settings& settings)
	:
	pos(pos)
{
	textureSheet.loadFromFile(settings.GetChracterSpriteFileName());
}

void Character::Draw(const Graphics& gfx)
{
	//set position
	sprite[0].position = pos;
	sprite[1].position = pos + sf::Vector2f((float)gfx.GetSpriteSize().x, 0.0f);
	sprite[2].position = pos + sf::Vector2f(gfx.GetSpriteSize());
	sprite[3].position = pos + sf::Vector2f(0.0f, (float)gfx.GetSpriteSize().y);

	ApplyTexture(3, true,true, gfx);

	gfx.GetRenderTarget().draw(sprite, &textureSheet);
}

void Character::Update(const float dt, const sf::Window& win)
{
	sf::Vector2f dir(0, 0);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		dir.y += 1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		dir.y -= 1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		dir.x += 1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		dir.x -= 1;
		
	//dir = (sf::Vector2f)sf::Mouse::getPosition(win) - pos;
	float length = sqrt((dir.x * dir.x) + (dir.y * dir.y));
	if (length != 0)
		dir = sf::Vector2f(dir.x / length, dir.y / length);

	pos += dir * dt * vel;
}

sf::Vector2f Character::GetPos() const
{
	return pos;
}

void Character::ApplyTexture(const int index, const bool flippedHorizontal, const bool flippedVertical, const Graphics& gfx)
{

	const sf::Vector2f texPos(index % (textureSheet.getSize().x / gfx.GetSpriteSize().x) * gfx.GetSpriteSize().x, index / (textureSheet.getSize().x / gfx.GetSpriteSize().x) * gfx.GetSpriteSize().y);

	if (!flippedHorizontal && !flippedVertical)
	{
		sprite[0].texCoords = texPos;
		sprite[1].texCoords = texPos + sf::Vector2f((float)gfx.GetSpriteSize().x, 0.0f);
		sprite[2].texCoords = texPos + sf::Vector2f(gfx.GetSpriteSize());
		sprite[3].texCoords = texPos + sf::Vector2f(0.0f, (float)gfx.GetSpriteSize().y);
	}
	else if (flippedHorizontal && !flippedVertical)
	{
		sprite[1].texCoords = texPos;
		sprite[0].texCoords = texPos + sf::Vector2f((float)gfx.GetSpriteSize().x, 0.0f);
		sprite[3].texCoords = texPos + sf::Vector2f(gfx.GetSpriteSize());
		sprite[2].texCoords = texPos + sf::Vector2f(0.0f, (float)gfx.GetSpriteSize().y);
	}
	else if (!flippedHorizontal && flippedVertical)
	{
		sprite[3].texCoords = texPos;
		sprite[2].texCoords = texPos + sf::Vector2f((float)gfx.GetSpriteSize().x, 0.0f);
		sprite[1].texCoords = texPos + sf::Vector2f(gfx.GetSpriteSize());
		sprite[0].texCoords = texPos + sf::Vector2f(0.0f, (float)gfx.GetSpriteSize().y);
	}
	else if (flippedHorizontal && flippedVertical)
	{
		sprite[2].texCoords = texPos;
		sprite[3].texCoords = texPos + sf::Vector2f((float)gfx.GetSpriteSize().x, 0.0f);
		sprite[0].texCoords = texPos + sf::Vector2f(gfx.GetSpriteSize());
		sprite[1].texCoords = texPos + sf::Vector2f(0.0f, (float)gfx.GetSpriteSize().y);
	}

}
