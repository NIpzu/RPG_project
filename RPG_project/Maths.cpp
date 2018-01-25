#include "Maths.h"

sf::Vector2f Maths::NormalizeVec(const sf::Vector2f in)
{
	float length = GetLength(in);
	if (length != 0)
		return sf::Vector2f(in.x / length, in.y / length);
	return sf::Vector2f(0.0f,0.0f);
}

float Maths::GetLengthSq(const sf::Vector2f in)
{
	return (in.x * in.x) + (in.y * in.y);
}

float Maths::GetLength(const sf::Vector2f in)
{
	return std::sqrtf(GetLengthSq(in));
}

sf::Vector2f Maths::MatchAXToBX(const sf::Vector2f a, const sf::Vector2f b)
{
	const float ratio = b.x / a.x;
	return a * ratio;
}

sf::Vector2f Maths::MatchAYToBY(const sf::Vector2f a, const sf::Vector2f b)
{
	const float ratio = b.y / a.y;
	return a * ratio;
}
