#pragma once
#include "Man.h"
#include "Common.h"


enum department { spintex, bms, pkims };

std::string departmentToString(department dep);

class Teacher : public Common
{
	std::string course;
	enum department dep;

public:
	Teacher();
	Teacher(Man nameSurname, std::string Course, department dep);

	std::string const GetNameFam();
	std::string ToShortString() override;
	std::string ToString() override;

	static void GetInfo(std::vector <Teacher> db);

	friend std::istream& operator>> (std::istream& is, Teacher& tech);
};