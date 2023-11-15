#pragma once
#include <string>
#include <vector>
#include "Man.h"

class Common {

public:
	Man nameSurname;
	virtual std::string ToShortString() = 0;
	virtual std::string ToString() = 0;
	void search(std::string fam) {};

	const bool operator == (Man manr);
};