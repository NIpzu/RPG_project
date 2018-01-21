#pragma once

#include <SFML\System.hpp>

class Angle
{
public:
	Angle(const float angle);
	Angle(const sf::Vector2f vec);
	float GetAngle() const;
	bool isBetween(const Angle ccwAngle, const Angle cwAngle) const;
private:
	float floatToAngle(const float value) const;
private:
	float angle;
};