#include "Employee.h"
#include <iostream>

Employee::Employee() {
	surname = "DefSurname";
	passportNumber = 1000000;
}

Employee::Employee(int passport, std::string surname)
{
	passportNumber = passport;
	this->surname = surname;
}

int Employee::GetPassport()
{
	return passportNumber;
}

std::string Employee::GetSurname()
{
	return surname;
}

void Employee::SetPassport(int passp)
{
	passportNumber = passp;
}

void Employee::SetSurname(std::string surname)
{
	this->surname = surname;
}

std::ostream& operator<<(std::ostream& os, Employee& empl)
{
	std::cout << empl.GetSurname() << " " << empl.GetPassport();
	return os;
}