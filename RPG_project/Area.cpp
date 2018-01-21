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

CircleSectorArea::CircleSectorArea(const sf::Vector2f center, const float radius, const Angle angleDir, const Angle angleWidth)
	:
	center(center),
	radius(radius),
	ccwAngle(Angle(angleDir.GetAngle() - (angleWidth.GetAngle() / 2.0f))),
	cwAngle(Angle(angleDir.GetAngle() + (angleWidth.GetAngle() / 2.0f)))
{
}

bool CircleSectorArea::isInArea(const sf::Vector2f pos) const
{
	const sf::Vector2f relPos = pos - center;
	Angle angle = Angle(relPos);



	return angle.isBetween(ccwAngle, cwAngle) && std::pow(relPos.x,2) + std::pow(relPos.y, 2) <= radius * radius;
}

TriangleArea::TriangleArea(const sf::Vector2f point0, const sf::Vector2f point1, const sf::Vector2f point2)
	:
	point0(point0),
	point1(point1),
	point2(point2)
{
}

bool TriangleArea::isInArea(const sf::Vector2f pos) const
{
	bool b1, b2, b3;

	b1 = (pos.x - point1.x) * (point0.y - point1.y) - (point0.x - point1.x) * (pos.y - point1.y) < 0.0f;
	b2 = (pos.x - point2.x) * (point1.y - point2.y) - (point1.x - point2.x) * (pos.y - point2.y) < 0.0f;
	b3 = (pos.x - point0.x) * (point2.y - point0.y) - (point2.x - point0.x) * (pos.y - point0.y) < 0.0f;

	return ((b1 == b2) && (b2 == b3));
}
