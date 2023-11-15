#pragma once
#include <string>

class Man {
	std::string name;
	std::string surname;

public:
	Man();
	Man(std::string name, std::string surname);
	std::string ToShortString();


	friend std::istream& operator>> (std::istream& is, Man& man);
};