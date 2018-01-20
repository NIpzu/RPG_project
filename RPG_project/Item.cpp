#include "Item.h"

std::string Item::GetName() const
{
	return name;
}

void Item::SetName(std::string newName)
{
	name = newName;
}
