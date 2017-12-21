#pragma once

#include <string>
#include <vector>
#include "TileTypes.h"

class Map
{
public:

private:
	std::vector<TileTypes> curMap;

private:
	struct MapTile
	{
	public:
		TileTypes GetType()
		{
			return TileTypes(type);
		}
		bool IsMoveable() {
			return (type & 0b1000000) == 0b10000000;
		}

	private:
		char type = 0b00000000;
		char entity = 0b00000000;
	};


};