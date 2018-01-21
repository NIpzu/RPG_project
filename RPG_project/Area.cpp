#include "Area.h"
#include <cmath>
#include <assert.h>

RectangleArea::RectangleArea(const sf::FloatRect area)
	:
	area(area)
{
}

bool RectangleArea::isInArea(const sf::Vector2f pos) const
{
	return area.contains(pos);
}

CircleArea::CircleArea(const sf::Vector2f center, const float radius)
	:
	center(center),
	radius(radius)
{
}

bool CircleArea::isInArea(const sf::Vector2f pos) const
{
	return std::pow(radius, 2) > std::pow(std::abs(center.x - pos.x), 2) + std::pow(std::abs(center.y - pos.y), 2);
}

CircleSector::CircleSector(const sf::Vector2f center, const float radius, const Angle angleDir, const Angle angleWidth)
	:
	center(center),
	radius(radius),
	ccwAngle(Angle(angleDir.GetAngle() - (angleWidth.GetAngle() / 2.0f))),
	cwAngle(Angle(angleDir.GetAngle() + (angleWidth.GetAngle() / 2.0f)))
{
}

bool CircleSector::isInArea(const sf::Vector2f pos) const
{
	const sf::Vector2f relPos = pos - center;
	Angle relAngle = Angle(relPos);



	return relAngle.isBetween(ccwAngle, cwAngle) && std::pow(relPos.x,2) + std::pow(relPos.y, 2) <= radius * radius;
}
