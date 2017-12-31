#pragma once
#include <vector>
#include <SFML\System.hpp>


class FileAcces
{
public:
	FileAcces(const std::string filename);


	void FileAcces::LoadToVector(const std::string filename, std::vector<char>& vec);
	void FileAcces::LoadToVector(std::vector<char>& vec);

private:

	std::string openedFile;
};