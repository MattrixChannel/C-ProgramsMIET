#include <iostream>
#include <iomanip>
#include "Bank.h"
#include "Man.h"
#include <string>

using namespace std;

#define MAXNAMELEN 30
#define DBNAME "save.txt"

int Bank::getId() { return id; }

using namespace std;

Man Bank::getFIO()
{
	return FIO;
}

Bank::Bank() {
	id = count + 1;
	FIO = Man();
	sum = 0;
	count++;
}

Bank::~Bank() {
	count--;
}

void Bank::defineBankAuto(Man fio, double _sum) {

	FIO = fio;

	if (FIO.surname.size() > longestSurname) {
		longestSurname = FIO.surname.size();
	}

	if (FIO.name.size() > longestName) {
		longestName = FIO.name.size();
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
		cout << setw(2) << u->getId() << setw(longestSurname + 1) << u->FIO.surname << setw(longestName + 1) << u->FIO.name << ' ' << u->sum << '\n';
		u++;
	}
}

const void Bank::operator + (double num) {
	sum += num;
}

const bool Bank::operator == (Man pers) {
	if (this->FIO == pers) {
		return true;
	}
	else return false;
}

istream& operator>> (istream& is, Bank& bnk)
{
	string bufSurname;
	string bufName;
	double bufSum;

	cout << "Surname: ";
	is >> bufSurname;

	cout << "Name: ";
	is >> bufName;

	cout << "Deposit: ";
	is >> bufSum;

	bnk.defineBankAuto(Man(bufSurname, bufName), bufSum);

	return is;
}

void Bank::getBankInfo() {
	cout << "\n" << setw(9) << "Id: " << id << endl;

	cout << setw(9) << "Surname: " << FIO.surname << endl;

	cout << setw(9) << "Name: " << FIO.name << endl;

	cout << setw(9) << "Deposit: " << sum << endl << endl;
}


int Bank::count = 0;
int Bank::longestName = 4;
int Bank::longestSurname = 7;