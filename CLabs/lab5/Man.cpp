#include "Man.h"
#include <iostream>

Man::Man()
{
	name = "BaseName";
	surname = "BaseSurname";
}

Man::Man(std::string name, std::string surname)
{
	this->name = name;
	this->surname = surname;
}

std::string Man::ToShortString() {
	return name + " " + surname;
}

std::istream& operator>>(std::istream& is, Man& man)
{
	std::cout << "Имя: ";
	is >> man.name;
	std::cout << "Фамилия: ";
	is >> man.surname;
	return is;
}
