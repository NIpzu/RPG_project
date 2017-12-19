#pragma once

#include <string>
#include <vector>

class Map
{
public:
	Map();

private:
	void LoadFromFile(std::string& filename);
	//	std::vector<>

	enum class TileTypes : char {
		empty,
		count
	};
private:
	struct MapTile
	{
	public:
		TileTypes GetType()
		{
			return TileTypes(type);
		}
		bool IsMoveable() {
			return type & 0b1000000 == 0b10000000;
		}

	private:
		char type = 0b00000000;
		char entity = 0b00000000;
	};


};