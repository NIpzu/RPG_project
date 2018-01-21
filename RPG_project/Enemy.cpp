#include "Enemy.h"
#include <iostream>

void Enemy::DealDamage(const float amount)
{
	health -= amount;
	if (health <= 0.0f)
	{
		std::cout << GetName() << " died!";
	}
}
