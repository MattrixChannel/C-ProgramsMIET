#include "Teacher.h"
#include <iostream>

Teacher::Teacher()
{
	course = "Информатика";
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
	std::cout << "Учителя: \nИмя Фамилия Курс Кафедра\n";
	for (int i = 0; i < db.size(); i++) {
		std::cout << db[i].ToString() << std::endl;
	}
}

std::string departmentToString(department dep)
{
	switch (dep) {
	case 0:
		return "Спинтех";
	case 1:
		return "БМС";
	case 2:
		return "ПКиМС";
	default:
		throw std::string{ "Неопознанная кафедра" };
	}
}

const bool Teacher::operator == (Man manr) {
	if (nameSurname.ToShortString() == manr.ToShortString()) return true;
	else return false;
}

std::istream& operator>> (std::istream& is, Teacher& tech)
{
	is >> tech.nameSurname;
	std::cout << "Курс: ";
	is >> tech.course;
	std::cout << "Кафедра (0 = spintex, 1 = bms, 2 = pkims): ";
	if (tech.dep != 0 && tech.dep != 1 && tech.dep != 2) {
		throw std::string{ "Неопознанная кафедра" };
	}
	return is;
}