#include "Character.h"

Character::Character(const sf::Vector2f & pos, const Settings& settings)
	:
	pos(pos)
{
	textureSheet.loadFromFile(settings.GetChracterSpriteFileName());
}

void Character::Draw(const Graphics & gfx) const
{
	gfx.DrawSprite(textureSheet, pos);
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
