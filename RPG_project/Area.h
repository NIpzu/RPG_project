#pragma once

#include <SFML\Graphics.hpp>
#include "Angle.h"

class Area
{
public:
	virtual bool isInArea(const sf::Vector2f pos) const = 0;
	virtual ~Area() = default;
};



class RectangleArea : public Area
{
public:
	RectangleArea(const sf::FloatRect area);
	bool isInArea(const sf::Vector2f pos) const;
private:
	const sf::FloatRect area;
};



class CircleArea : public Area
{
public:
	CircleArea(const sf::Vector2f center, const float radius);
	bool isInArea(const sf::Vector2f pos) const;
private:
	const sf::Vector2f center;
	const float radius;
};



class CircleSector
{
public:
	CircleSector(const sf::Vector2f center, const float radius, const Angle angleDir, const Angle angleWidth);
	bool isInArea(const sf::Vector2f pos) const;
private:
	const sf::Vector2f center;
	const float radius;
	const Angle ccwAngle;
	const Angle cwAngle;
};