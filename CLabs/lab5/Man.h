#pragma once
#include <string>

class Man {
	std::string name;
	std::string surname;

public:
	Man();
	Man(std::string name, std::string surname);
	std::string ToShortString();

	
};