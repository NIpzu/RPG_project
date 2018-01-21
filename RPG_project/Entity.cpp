#include "Entity.h"

sf::Vector2f Entity::GetPos() const
{
	return pos;
}

std::string Entity::GetName() const
{
	return name;
}

void Entity::SetName(const std::string newName)
{
	name = newName;
}
