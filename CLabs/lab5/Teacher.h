#pragma once
#include "Man.h"
#include "Common.h"


enum department { spintex, bms, pkims };

class Teacher : public Common
{
	Man nameSurname;
	std::string Course;
	enum department dep;

public:
	Teacher();
	Teacher(Man nameSurname, std::string Course, department dep);

	std::string ToShortString() override;
	
};