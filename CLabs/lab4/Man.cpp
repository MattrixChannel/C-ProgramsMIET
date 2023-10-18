#include <iostream>
#include <iomanip>
#include "Bank.h"
#include "Man.h"
#include <string>

using namespace std;

string Man::getName() { return name; }
string Man::getSurname() { return surname; }

Man::Man()
{
	surname = "DefaultSurname";
	name = "DefaultName";
}

Man::Man(string _surname, string _name)
{
	surname = _surname;
	name = _name;
}

const bool Man::operator == (Man manr) {
	if (name == manr.name && surname == manr.surname) return true;
	else return false;
}