#pragma once

#include "Employee.h"

class Company {
	Employee* employees;
	std::string companyName;
	int numberOfEmployees;


public:

	Employee* GetEmployees();
	std::string GetCompanyName();
	int GetNumberOfEmployees();

	void SetCompanyName(std::string name);
	void SetNumberOfEmployees(int num);

	void AddEmployee(Employee empl);

	Company();
	~Company();

	friend std::istream& operator>> (std::istream& is, Company& comp);
	friend std::ostream& operator<<(std::ostream& os, Company& comp);

	const bool operator <=(Company& comp);
};