#pragma once
#include "Graphics.h"
#include <SFML\System.hpp>
#include <memory>
#include "Weapon.h"

class Character
{
public:
	Character(const sf::Vector2f& pos);
	void Draw(const Graphics& gfx, const Settings& settings) const;
	void Update(const float dt);
	sf::Vector2f GetPos() const;
private:
	sf::Vector2f pos;
	float vel = 100;
	std::unique_ptr<Weapon> weapon;
};
