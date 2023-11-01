#include "Man.h"

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
