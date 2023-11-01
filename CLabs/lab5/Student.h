#pragma once
#include "Man.h"
#include "Common.h"

class Student : public Common
{ 
	Man nameSurname;
	int group;
public:
	std::string ToShortString() override;

	Student();
	Student(Man namesurname, int group);
};