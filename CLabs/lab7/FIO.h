#pragma once
#include<string>
#include "Bank.h"

class FIO {
public:
	std::string name;
	std::string surname;

	FIO() {
		name = "DefName";
		surname = "DefSurname";
	}

	FIO(std::string nam, std::string surn) {
		name = nam;
		surname = surn;
	}

	const std::string getName() {
		return name;
	}

	const std::string getSurname() {
		return surname;
	}

	const std::string ToString() {
		return name + " " + surname;
	}
};