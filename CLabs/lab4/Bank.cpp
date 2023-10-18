#include <iostream>
#include <iomanip>
#include "Bank.h"

#define MAXNAMELEN 30
#define DBNAME "save.txt"

using namespace std;


int Bank::getId() { return id; };
void Bank::setId(int num) { id = num; };
char* Bank::getSurname() { return surname; };
char* Bank::getName() { return name; };

Bank::Bank() {
	id = count + 1;
	name = new char[MAXNAMELEN];
	strcpy_s(name, 12, "DefaultName");
	surname = new char[MAXNAMELEN];
	strcpy_s(surname, 15, "DefaultSurname");
	sum = 0;
	count++;
}

Bank::~Bank() {
	delete[] name;
	delete[] surname;
	count--;
}

void Bank::defineBankManual() {
	char buf[MAXNAMELEN];

	cout << "Surname: ";
	cin >> buf;

	strcpy_s(surname, strlen(buf) + 1, buf);

	if (strlen(buf) > longestSurname) longestSurname = strlen(buf);

	cout << "Name: ";
	cin >> buf;

	strcpy_s(name, strlen(buf) + 1, buf);

	if (strlen(buf) > longestName) longestName = strlen(buf);

	cout << "Deposit: ";
	cin >> sum;
}

void Bank::defineBankAuto(char* _name, char* _surname, double _sum) {
	strcpy_s(surname, strlen(_surname) + 1, _surname);

	if (strlen(_surname) > longestSurname) {
		longestSurname = strlen(_surname);
	}

	strcpy_s(name, strlen(_name) + 1, _name);

	if (strlen(_name) > longestName) {
		longestName = strlen(_name);
	}

	sum = _sum;
	id = count;
}

void Bank::getAccsWithDepositMoreThan(Bank* db, double summ) {
	for (int i = 0; i < count; i++)
	{
		if (db[i].sum > summ) db[i].getBankInfo();
	}
}

void Bank::dbInfo(Bank* db) {
	Bank* u = db;
	cout << "ID" << setw(longestSurname + 1) << "Surname" << setw(longestName + 1) << "Name" << ' ' << "Debt" << endl;
	cout << "---------------------------------------------\n\n";
	for (int i = 0; i < Bank::count; i++) {
		cout << setw(2) << u->getId() << setw(longestSurname + 1) << u->getSurname() << setw(longestName + 1) << u->getName() << ' ' << u->sum << '\n';
		u++;
	}
}

const void Bank::operator + (double num) {
	sum += num;
}

istream& operator>> (istream& is, Bank& bnk)
{
	cout << "Surname: ";
	is >> bnk.name;
	cout << "Name: ";
	is >> bnk.surname;
	cout << "Deposit: ";
	is >> bnk.sum;
	return is;
}

void Bank::getBankInfo() {
	cout << "\n" << setw(9) << "Id: " << id << endl;

	cout << setw(9) << "Surname: " << surname << endl;

	cout << setw(9) << "Name: " << name << endl;

	cout << setw(9) << "Deposit: " << sum << endl << endl;
}


int Bank::count = 0;
int Bank::longestName = 4;
int Bank::longestSurname = 7;