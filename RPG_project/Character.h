#pragma once
#include "Graphics.h"
#include <SFML\System.hpp>

class Character
{
public:
	Character(const sf::Vector2f& pos);
	void Draw(const Graphics& gfx, const Settings& settings) const;
	void Update();
private:
	sf::Vector2f pos;

};
