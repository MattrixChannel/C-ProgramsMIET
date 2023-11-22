#include "Company.h"
#include <iostream>

Employee* Company::GetEmployees()
{
	return employees;
}

std::string Company::GetCompanyName()
{
	return companyName;
}

int Company::GetNumberOfEmployees()
{
	return numberOfEmployees;
}

void Company::AddEmployee(Employee empl)
{
	int size = numberOfEmployees;

	Employee* newDb = new Employee[size + 1];

	for (int i = 0; i < size; i++) {
		newDb[i].SetPassport(employees[i].GetPassport());
		newDb[i].SetSurname(employees[i].GetSurname());
	}

	delete[] employees;
	employees = newDb;
	employees[numberOfEmployees].SetPassport(empl.GetPassport());
	employees[numberOfEmployees].SetSurname(empl.GetSurname());
	numberOfEmployees++;
}

void Company::SetCompanyName(std::string name)
{
	companyName = name;
}

void Company::SetNumberOfEmployees(int num)
{
	numberOfEmployees = num;
}

Company::Company()
{
	numberOfEmployees = 1;
	employees = new Employee[1];
	companyName = "DefCompanyName";
}

Company::~Company()
{
	delete[] employees;
}

const bool Company::operator<=(Company& comp)
{
	if (this->numberOfEmployees <= comp.numberOfEmployees) return true;
	else return false;
}

std::istream& operator>>(std::istream& is, Company& comp)
{
	std::cout << "Input Company Name: ";
	std::string name;
	std::cin >> name;
	comp.companyName = name;
	return is;
}

std::ostream& operator<<(std::ostream& os,Company& comp)
{
	os << comp.companyName << ", " << comp.numberOfEmployees << ": \n";
	for (int i = 0; i < comp.numberOfEmployees; i++) {
		os << comp.employees[i] << std::endl;
	}
	return os;
}