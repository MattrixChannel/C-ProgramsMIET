#include <iostream>
#include <fstream>
#include <iomanip>
#include "Bank.h"
#include "Man.h"
#include <string>

using namespace std;

#define MAXNAMELEN 30
#define DBNAME "save.txt"


/* Общие требования к заданиям - LAB 4
1.	Продолжить работу над проектом
2.	Создать новый класс и встроить его объект в существующий класс, согласно заданию
3.	Данные размещаются в динамической памяти.
4.	Для выполнения функций, указанных в задании, написать диалоговый интерфейс, позволяющий выполнять функции в произвольном порядке многократно
5.	При выполнении функции «выход из программы» нужно сохранить базу на диске
6.	Первичное создание базы – ввод данных с клавиатуры
7.	Если программа уже запускалась, то данные загружаются из файла перед выходом на диалог. Иными словами вносятся изменения и дополнения в
		уже существующую базу данных.
8.	Обязательные функции для всех вариантов:
	•	добавить несколько новых элементов в базу
	•	распечатка данных в табличном виде
	•	выход из программы
9.	Остальные функции для работы с базой указаны в задании индивидуально.
10.	 Примеры диалогового интерфейса и табличного вывода смотрите в лабораторной работе №1
11.	Перегруженные операторы реализовывать как с помощью дружественной функции (ДФ), так и с помощью метода класса (МК).
		Если в задании не указан метод реализации – решаете по своему усмотрению.
*/

void cpyDB(Bank* Don, Bank* Rec, int size) {
	for (int i = 0; i < size; i++) {
		Rec[i].defineBankAuto(Don[i].FIO, Don[i].sum);
		Rec[i].id = i + 1;
	}
	Rec[size].id = size + 1;
}

Bank* expandDb(Bank* db) {
	int size = Bank::count;

	Bank* newDb = new Bank[size + 1];

	for (int i = 0; i < size; i++) {
		newDb[i].defineBankAuto(db[i].FIO, db[i].sum);
		newDb[i].id = i + 1;
	}
	newDb[size].id = size + 1;

	delete[] db;
	return newDb;
}

void motd() {
	cout << "\n/////////////// What do you want to do?\n";
	cout << "Save DB to hard drive:                1\n";
	cout << "Show the DB:                          2\n";
	cout << "Add new account:                      3\n";
	cout << "Get account info:                     4\n";
	cout << "Find accounts with deposit more than: 5\n";
	cout << "Add number to the deposit:            6\n";
	cout << "Testing                               7\n";
	cout << "Exit:                                 0\n";
	cout << "\nType a number: ";
}

void test() {
	Man pers1 = Man("Brasl", "Petr");
	Bank bnk;
	bnk.defineBankAuto(Man("Brasl", "Petr"), 1000);
	cout << (bnk == pers1);

	pers1.name = "Petr1";
	cout << (bnk == pers1);

	cout << (pers1 == bnk.getFIO());

}

int main() {

	Bank* db = new Bank[1];
	fstream dbFile;
	dbFile.open(DBNAME);


	int except = 0;

	string bufSurname;
	string bufName;
	double bufSum;

	if (dbFile.is_open()) {
		for (int i = 0; dbFile.good(); i++) {
			dbFile >> bufSurname;
			dbFile >> bufName;
			dbFile >> bufSum;

			if (i != 0) {
				db = expandDb(db);
			}

			db[i].defineBankAuto(Man(bufSurname, bufName), bufSum);
		}
	}

	dbFile.close();
	/*
	for (int i = 0; !feof(dbFile); i++) {

		char bufName[MAXNAMELEN];
		char bufSurname[MAXNAMELEN];
		double bufSum;

		//newAcc.surname = new char[strlen(buf) + 1];
		//strcpy_s(newAcc.surname, strlen(buf) + 1, buf);

		//db[i].surname = new char[MAXNAMELEN];
		//db[i].name = new char[MAXNAMELEN];

		fscanf_s(dbFile, "%s", bufSurname, MAXNAMELEN);

		if (feof(dbFile)) {
			break;
		}

		fscanf_s(dbFile, "%s", bufName, MAXNAMELEN);

		fscanf_s(dbFile, "%lf", &(bufSum));
		if (i != 0) {
			db = expandDb(db);
		}

		db[i].defineBankAuto(Man(bufSurname, bufName), bufSum);
	}
	fclose(dbFile);
	*/

	Bank::dbInfo(db);

	while (true) {
		motd();
		char var;
		cin >> var;

		bool found4 = false;
		double sum5 = 0;
		int num6 = 0;
		int id6 = 0;

		int id4 = -1;

		Man iMan4;

		switch (var) {
		case '1':
			dbFile.open(DBNAME, ios::out);

			if (dbFile.is_open()) {
				for (int i = 0; i < Bank::count; i++) {
					dbFile << db[i].getFIO().getSurname() + " ";
					dbFile << db[i].getFIO().getName() + " ";
					dbFile << db[i].sum;
					if (i != Bank::count - 1) dbFile << "\n";
				}
			}

			dbFile.close();

			cout << "DB has been successfully saved to hard drive";

			break;

		case '2':
			Bank::dbInfo(db);
			break;

		case '3':

			if (Bank::count == 1 && db[0].getFIO().getSurname() == "DefaultSurname") {
				cin >> db[0];
				break;
			}

			db = expandDb(db);

			cout << endl;

			cin >> db[Bank::count - 1];

			cout << "\nBank has been succesfully added to data base" << endl;

			break;

		case '4':
			cout << "Enter Surname: ";
			char surname4[MAXNAMELEN];
			cin >> surname4;
			cout << "Enter Name: ";
			char name4[MAXNAMELEN];
			cin >> name4;

			iMan4 = Man(surname4, name4);

			for (int i = 0; i < Bank::count; i++) {
				if (iMan4 == db[i].getFIO()) {
					found4 = true;
					db[i].getBankInfo();
					break;
				}
			}

			if (!found4) cout << "\nNot found\n";

			break;

		case '5':
			cout << "Enter a number, accounts with deposit higher than it will be shown:" << endl;
			cin >> sum5;

			Bank::getAccsWithDepositMoreThan(db, sum5);

			break;

		case '6':
			cout << "Enter a client id: ";
			cin >> id6;
			id6--;

			cout << "Enter how much you want to add: ";
			cin >> num6;
			db[id6] + num6;

			cout << "Done!" << endl;

			break;

		case '7':
			test();
			break;

		case '0':
			//cout << Bank::count;
			delete[] db;
			return 0;
		default:
			cout << "Unexpected symbol, please try again\n";
			break;
		}
	}
}