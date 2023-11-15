#include "Teacher.h"
#include <iostream>

Teacher::Teacher()
{
	course = "�����������";
	dep = bms;
}

Teacher::Teacher(Man nameSurname, std::string course, department dep)
{
	this->nameSurname = nameSurname;
	this->course = course;
	this->dep = dep;
}

std::string const Teacher::GetNameFam()
{
	return nameSurname.ToShortString();
}

std::string Teacher::ToShortString()
{
	return nameSurname.ToShortString() + " " + course + " " + std::to_string(dep);
}

std::string Teacher::ToString()
{
	return nameSurname.ToShortString() + " " + course + " " + departmentToString(dep);
}

void Teacher::GetInfo(std::vector<Teacher> db)
{
	std::cout << "�������: \n��� ������� ���� �������\n";
	for (int i = 0; i < db.size(); i++) {
		std::cout << db[i].ToString() << std::endl;
	}
}

std::string departmentToString(department dep)
{
	switch (dep) {
	case 0:
		return "�������";
	case 1:
		return "���";
	case 2:
		return "�����";
	default:
		throw std::string{ "������������ �������" };
	}
}

std::istream& operator>> (std::istream& is, Teacher& tech)
{
	is >> tech.nameSurname;
	std::cout << "����: ";
	is >> tech.course;
	std::cout << "������� (0 = spintex, 1 = bms, 2 = pkims): ";
	if (tech.dep != 0 && tech.dep != 1 && tech.dep != 2) {
		throw std::string{ "������������ �������" };
	}
	return is;
}