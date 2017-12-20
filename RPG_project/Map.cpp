#include "Map.h"
#include <SFML\System.hpp>
#include <iostream>

void Map::LoadFromFile(std::string & filename)
{
	sf::FileInputStream file;
	file.open(filename);
	int filesize = file.getSize();
	std::vector<char> FileData;
	FileData.resize(filesize);
	if (file.read(FileData.data(), filesize) != filesize)
	{
		std::cout << "Something Went Wrong While Reading From " << filename << "!" << std::endl;
	}
}
