#pragma once
#include<iostream>

using namespace std;

class Bank {
	int id;
	char* name;
	char* surname;

public:
	double sum;

	static int count;
	static int longestName;
	static int longestSurname;

	int getId();
	char* getSurname();
	char* getName();

	Bank();

	~Bank();

	void defineBankAuto(char* _name, char* _surname, double _sum);

	static void getAccsWithDepositMoreThan(Bank* db, double summ);

	static void dbInfo(Bank* db);

	const void operator + (double num);

	friend void cpyDB(Bank* Don, Bank* Rec, int size);

	friend Bank* expandDb(Bank* db);

	friend istream& operator>> (istream& is, Bank& bnk);

	void getBankInfo();
};