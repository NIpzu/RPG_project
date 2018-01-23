#pragma once
#include "Graphics.h"
#include <SFML\Graphics.hpp>
#include <memory>
#include "Weapon.h"

class Character
{
public:
	Character(const sf::Vector2f& pos, const Settings& settings);
	void Draw(const Graphics& gfx);
	void Update(const float dt);
	sf::Vector2f GetPos() const;
private:
	sf::Vector2f pos;
	float vel = 100;
	std::unique_ptr<Weapon> weapon;
	float health;

	sf::Texture textureSheet;
	sf::VertexArray sprite{ sf::Quads,4 };
};
