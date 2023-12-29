#pragma once
#include <string>
#include <iostream>
#include "FIO.h"

class Bank {
	int id;
	FIO fio;

public:
	double sum;

	static const int MAXNAMELEN = 30;
	static std::string DBNAME;

	static int count;
	static int longestName;
	static int longestSurname;

	int getId() { return id; };
	void setId(int num) { id = num; };
	const std::string getSurname() { return fio.getSurname(); };
	const std::string getName() { return fio.getName(); };

	Bank() {
		id = count + 1;
		fio = FIO();
		sum = 0;
	}

	~Bank() {
	}

	const std::string ToString() {
		return fio.ToString() + ' ' + std::to_string(sum);
	}

	void defineBankManual() {

		std::cout << "Surname: ";
		std::cin >> fio.surname;

		if (fio.surname.size() > longestSurname) longestSurname = fio.surname.size();

		std::cout << "Name: ";
		std::cin >> fio.name;

		if (fio.name.size() > longestName) longestName = fio.surname.size();

		std::cout << "Deposit: ";
		std::cin >> sum;
	}

	void defineBankAuto(std::string _surname, std::string _name, double _sum) {
		fio.surname = _surname;

		if (_surname.size() > longestSurname) {
			longestSurname = _surname.size();
		}

		fio.name = _name;

		if (_name.size() > longestName) {
			longestName = _name.size();
		}

		sum = _sum;
		id = count;
	}


	const void operator + (double num) {
		sum += num;
	}

	const bool operator == (Bank& rb) {
		return this->ToString() == rb.ToString();
	}

	friend std::istream& operator>> (std::istream& is, Bank& bnk)
	{
		std::cout << "Surname: ";
		is >> bnk.fio.name;
		std::cout << "Name: ";
		is >> bnk.fio.surname;
		std::cout << "Deposit: ";
		is >> bnk.sum;
		return is;
	}

	friend std::ostream& operator<< (std::ostream& os, Bank& bnk)
	{
		os << bnk.ToString();
		return os;
	}
};

int Bank::count = 0;
int Bank::longestName = 4;
int Bank::longestSurname = 7;
std::string Bank::DBNAME = "save.txt";