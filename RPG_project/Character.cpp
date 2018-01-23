#include "Character.h"

Character::Character(const sf::Vector2f& pos, const Settings& settings)
	:
	pos(pos)
{
	textureSheet.loadFromFile(settings.GetChracterSpriteFileName());
}

void Character::Draw(const Graphics& gfx)
{
	sprite[0].position = pos;
	sprite[1].position = pos + sf::Vector2f((float)gfx.GetSpriteSize().x, 0.0f);
	sprite[2].position = pos + sf::Vector2f(gfx.GetSpriteSize());
	sprite[3].position = pos + sf::Vector2f(0.0f, (float)gfx.GetSpriteSize().y);

	sprite[0].texCoords = { 0,0 };
	sprite[1].texCoords = sf::Vector2f((float)gfx.GetSpriteSize().x, 0.0f);
	sprite[2].texCoords = sf::Vector2f(gfx.GetSpriteSize());
	sprite[3].texCoords = sf::Vector2f(0.0f, (float)gfx.GetSpriteSize().y);

	gfx.GetRenderTarget().draw(sprite, &textureSheet);
}

void Character::Update(const float dt)
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

	float length = sqrt((dir.x * dir.x) + (dir.y * dir.y));
	if (length != 0)
		dir = sf::Vector2f(dir.x / length, dir.y / length);

	pos += dir * dt * vel;
}

sf::Vector2f Character::GetPos() const
{
	return pos;
}
