#pragma once 
#include <iostream>
#include <iomanip>
#include "Man.h"
#include <string>

using namespace std;

class Bank {
	int id;
	Man FIO;

public:
	double sum;

	static int count;
	static int longestName;
	static int longestSurname;

	int getId();
	Man getFIO();

	Bank();

	~Bank();

	void defineBankAuto(Man fio, double _sum);

	static void getAccsWithDepositMoreThan(Bank* db, double summ);

	static void dbInfo(Bank* db);

	const void operator + (double num);

	const bool operator == (Man pers);

	friend void cpyDB(Bank* Don, Bank* Rec, int size);

	friend Bank* expandDb(Bank* db);

	friend istream& operator>> (istream& is, Bank& bnk);

	void getBankInfo();

	friend Man;
	friend void test();
};