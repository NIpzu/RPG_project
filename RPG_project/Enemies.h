#pragma once

#include <vector>
#include "Enemy.h"
#include "Graphics.h"
#include "Area.h"

class Enemies
{
public:
	Enemies();
	void DealDamage(const Area& area, const float amount);
	void Update(const float dt);
	void Draw(const Graphics& gfx);
private:
	std::vector<Enemy> enemyVec;
};