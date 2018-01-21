#include "Enemies.h"

void Enemies::DealDamage(const Area& area, const float amount)
{
	for (auto& e : enemyVec)
	{
		if (area.isInArea(e.GetPos()))
		{
			e.DealDamage(amount);
		}
	}
}
