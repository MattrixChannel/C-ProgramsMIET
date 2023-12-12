#pragma once
#include <string>

class Man {
	std::string name;
	std::string surname;

public:
	Man();
	Man(std::string name, std::string surname);
	std::string ToShortString();

	Man& operator= (const Man& m) {
		this->name = m.name;
		this->surname = m.surname;
		return *this;
	}

	friend std::istream& operator>> (std::istream& is, Man& man);
};