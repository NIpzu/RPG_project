#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	virtual ~Enemy() = default;
	void DealDamage(const float amount);
private:
	float health;
};
