#pragma once
#include "Graphics.h"
#include <SFML\System.hpp>

class Character
{
public:
	Character(const sf::Vector2f& pos);
	void Draw(Graphics& gfx) const;
private:
	sf::Vector2f pos;
};
