#include "Angle.h"
#include <cmath>

Angle::Angle(const float angle)
	:angle(floatToAngle(angle))
{
}

Angle::Angle(const sf::Vector2f vec)
{

	sf::Vector2f normalizedVec;

	float length = sqrt((vec.x * vec.x) + (vec.y * vec.y));
	if (length != 0)
		normalizedVec = sf::Vector2f(vec.x / length, vec.y / length);

	if (normalizedVec.x >= 0.0f && normalizedVec.y >= 0.0f)
	{
		angle = (90.0f - std::abs(std::asin(normalizedVec.y)) * 180 / 3.14159265358979f);
	}
	else if (normalizedVec.x < 0.0f && normalizedVec.y >= 0.0f)
	{
		angle = (270.0f + std::abs(std::asin(normalizedVec.y)) * 180 / 3.14159265358979f);
	}
	else if (normalizedVec.x >= 0.0f && normalizedVec.y < 0.0f)
	{
		angle = (90.0f + std::abs(std::asin(normalizedVec.y)) * 180 / 3.14159265358979f);
	}
	else if (normalizedVec.x < 0.0f && normalizedVec.y < 0.0f)
	{
		angle = (270.0f - std::abs(std::asin(normalizedVec.y)) * 180 / 3.14159265358979f);
	}
}

float Angle::GetAngle() const
{
	return angle;
}

bool Angle::isBetween(const Angle ccwAngle, const Angle cwAngle) const
{
	if (ccwAngle.GetAngle() < cwAngle.GetAngle())
	{
		return GetAngle() <= cwAngle.GetAngle() && GetAngle() >= ccwAngle.GetAngle();
	}
	else
	{
		return GetAngle() <= cwAngle.GetAngle() || GetAngle() >= ccwAngle.GetAngle();
	}
	return false;
}

float Angle::floatToAngle(const float value) const
{
	float returnVal = std::fmod(value, 360.0f);
	if (returnVal < 0.0f)
	{
		return returnVal + 360.0f;
	}
	return returnVal;
}
