#pragma once
#include <SFML\System.hpp>

class Entity
{
public:
	virtual void Update() = 0;
	virtual ~Entity() = default;
private:
	sf::Vector2f pos;
};