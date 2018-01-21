#pragma once
#include <SFML\System.hpp>
#include <string>

class Entity
{
public:
	virtual void Update() = 0;
	virtual ~Entity() = default;
	sf::Vector2f GetPos() const;
	std::string GetName() const;
protected:
	void SetName(const std::string newName);
private:
	sf::Vector2f pos;
	std::string name;
};