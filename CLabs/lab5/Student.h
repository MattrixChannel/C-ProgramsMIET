#pragma once
#include "Man.h"
#include "Common.h"
//#include <iostream>

class Student : public Common
{ 
	Man nameSurname;
	int group;
public:
	std::string ToShortString() override;

	Student();
	Student(Man namesurname, int group);

	static void GetInfo(std::vector <Student> db);

	std::string const GetNameFam();

	const bool operator == (Man manr);

	friend std::istream& operator>> (std::istream& is, Student& stud);
};