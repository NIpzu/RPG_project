#pragma once
#include <vector>
#include <SFML\System.hpp>


class FileAcces
{
public:
	FileAcces(std::string& filename);


	std::vector<char>* FileAcces::LoadToVector(std::string& filename);
	std::vector<char>* FileAcces::LoadToVector();

private:

	std::string openedFile;
};