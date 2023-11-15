#pragma once
#include "Man.h"
#include "Common.h"


enum department { spintex, bms, pkims };

std::string departmentToString(department dep);

class Teacher : public Common
{
	Man nameSurname;
	std::string course;
	enum department dep;

public:
	Teacher();
	Teacher(Man nameSurname, std::string Course, department dep);

	std::string const GetNameFam();
	std::string ToShortString() override;
	std::string ToString();

	static void GetInfo(std::vector <Teacher> db);

	const bool operator == (Man manr);

	friend std::istream& operator>> (std::istream& is, Teacher& tech);
};