#include "FileAcces.h"
#include <iostream>
#include <limits>


FileAcces::FileAcces(const std::string filename)
	:
	openedFile(filename)
{
}

void FileAcces::LoadToVector(const std::string filename, std::vector<char>& vec)
{
	openedFile = filename;
	LoadToVector(vec);
}

void FileAcces::LoadToVector(std::vector<char>& vec)
{
	sf::FileInputStream file;
	file.open(openedFile);

	auto filesize = file.getSize();

	vec.resize(filesize);

	if (file.read(vec.data(), filesize) != filesize)
	{
		std::cout << "Something went wrong while reading from " << openedFile << "!" << std::endl;
	}
}
