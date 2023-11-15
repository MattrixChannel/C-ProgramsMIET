#include "Common.h"
#include <iostream>

std::string Common::ToShortString()
{
	return "";
}

const bool Common::operator == (Man manr) {
	if (nameSurname.ToShortString() == manr.ToShortString()) return true;
	else return false;
}

