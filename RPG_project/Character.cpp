#include "Character.h"

Character::Character(const sf::Vector2f & pos)
	:
	pos(pos)
{
}

void Character::Draw(const Graphics & gfx, const Settings& settings) const
{
	gfx.DrawSprite(15, pos);
	sf::View newView = gfx.GetView();
	newView.setCenter(pos + (sf::Vector2f(settings.GetSpriteSizeXScale()) / 2.0f));
}
