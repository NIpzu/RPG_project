#pragma once
#include <string>

class Item
{
public:
	virtual ~Item() = default;
	std::string GetName() const;
protected:
	void SetName(std::string newName);
private:
	std::string name;
};