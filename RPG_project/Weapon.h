#pragma once

#include "Item.h"

class Weapon : public Item
{
public:
	virtual ~Weapon() = default;
	virtual void Use() = 0;
private:
	int baseDMG;
	float durability;
};