#pragma once
#include <iostream>
#include <iomanip>
#include "Bank.h"
#include <string>

using namespace std;

class Man {
private:
	string surname;
	string name;

public:
	Man();

	Man(string _surname, string _name);

	string getSurname();
	string getName();

	const bool operator == (Man manr);

	friend class Bank;
	friend void test();
};