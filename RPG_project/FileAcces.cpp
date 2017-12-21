#include "FileAcces.h"
#include <iostream>
#include <limits>


FileAcces::FileAcces(std::string& filename)
	:
	openedFile(filename)
{
}


std::vector<char>* FileAcces::LoadToVector(std::string& filename)
{
	openedFile = filename;
	return LoadToVector();
}

std::vector<char>* FileAcces::LoadToVector()
{
	std::vector<char>* fileData = new std::vector<char>;

	sf::FileInputStream file;
	file.open(openedFile);

	auto filesize = file.getSize();

	if (filesize > std::numeric_limits<unsigned int>::max())
	{
		std::cout << "Size of file " << openedFile << "too big!" << std::endl;
	}

	fileData->resize(unsigned int(filesize));

	if (file.read(fileData->data(), filesize) != filesize)
	{
		std::cout << "Something went wrong while reading from " << openedFile << "!" << std::endl;
	}

	return fileData;
}
