#pragma once

#include <string>

class Employee {
	int passportNumber;
	std::string surname;

public:
	Employee();
	Employee(int passport, std::string surname);

	int GetPassport();
	std::string GetSurname();

	void SetPassport(int passp);
	void SetSurname(std::string surname);

	friend std::ostream& operator<<(std::ostream& os, Employee& empl);
};