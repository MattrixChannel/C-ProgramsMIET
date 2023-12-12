#include "Man.h"
#include "Common.h"
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
	std::cout << "���: ";
	is >> man.name;
	if (Common::has_number(man.name)) throw std::string{ "���������� ����������� ������� � �����" };
	std::cout << "�������: ";
	is >> man.surname;
	if (Common::has_number(man.surname)) throw std::string{ "���������� ����������� ������� � �����" };
	return is;
}