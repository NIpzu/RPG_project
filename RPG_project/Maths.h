#pragma once

#include <SFML\System.hpp>
#include <cmath>

namespace Maths
{
	sf::Vector2f NormalizeVec(const sf::Vector2f in);
	float GetLengthSq(const sf::Vector2f in);
	float GetLength(const sf::Vector2f in);
	sf::Vector2f MatchAXToBX(const sf::Vector2f a, const sf::Vector2f b);
	sf::Vector2f MatchAYToBY(const sf::Vector2f a, const sf::Vector2f b);


}