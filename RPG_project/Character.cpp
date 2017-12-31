#include "Character.h"


Character::Character(const sf::Vector2f & pos)
	:
	pos(pos)
{
}

void Character::Draw(const Graphics & gfx) const
{
	gfx.DrawSprite(5, pos);
}
