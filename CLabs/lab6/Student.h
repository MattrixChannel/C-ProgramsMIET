#pragma once
#include "Man.h"
#include "Common.h"
//#include <iostream>

class Student : public Common
{
	int group;
public:
	std::string ToShortString() override;
	std::string ToString() override;

	Student();
	Student(Man namesurname, int group);

	static void GetInfo(std::vector <Student> db);

	std::string const GetNameFam();

	friend std::istream& operator>> (std::istream& is, Student& stud);

	friend std::ostream& operator<< (std::ostream& os, Student& stud);

	Student& operator= (const Student& stud) {
		this->nameSurname = stud.nameSurname;
		this->group = stud.group;
		return *this;
	}
};