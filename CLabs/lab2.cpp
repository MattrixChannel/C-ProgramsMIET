#include <iostream>
#include <iomanip>

#define MAXNAMELEN 30
#define DBNAME "save.txt"

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
	
	int getId() { return id; };
	char* getSurname() { return surname; };
	char* getName() { return name; };

	Bank() {
		id = count+1;
		name = new char[MAXNAMELEN];
		strcpy_s(name, 2, " ");
		surname = new char[MAXNAMELEN];
		strcpy_s(surname, 2, " ");
		sum = 0;
		count++;
	}

	~Bank() {
		delete[] name;
		delete[] surname;
	}

	void defineBankManual() {
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

	void defineBankAuto(char* _name, char* _surname, double _sum) {
		strcpy_s(surname, strlen(_surname) + 1, surname);

		if (strlen(_surname) > longestSurname) longestSurname = strlen(_surname);

		strcpy_s(name, strlen(_name) + 1, name);

		if (strlen(_name) > longestName) longestName = strlen(_name);

		sum = _sum;
		id = count + 1;
		count++;
	}
};

int Bank::count = 0;
int Bank::longestName = 4;
int Bank::longestSurname = 7;

/*
1.	Во всех вариантах нужно создать базу данных, согласно варианту задания
2.	Данные размещаются в динамической памяти.
3.	Обязательные функции для всех вариантов:
•	добавить новый элемент в базу
•	распечатка данных в табличном виде
•	выход из программы
4.	Остальные функции для работы с базой указаны в задании индивидуально.
5.	Для выполнения функций, указанных в задании, написать диалоговый интерфейс, позволяющий выполнять функции в произвольном порядке многократно
6.	При выполнении функции «выход из программы» нужно сохранить базу на диске
7.	Первичное создание базы – ввод данных с клавиатуры
8.	Если программа уже запускалась, то данные загружаются из файла перед выходом на диалог. Иными словами вносятся изменения и дополнения в уже существующую базу данных.
*/

void dbInfo(Bank* db) {
	Bank* u = db;
	cout << "ID" << setw(Bank::longestSurname) << "Surname" << setw(Bank::longestName) << "Name" << ' ' << "Debt" << endl;
	cout << "---------------------------------------------\n\n";
	for (int i = 0; i < Bank().count; i++) {
		cout << setw(2) << u->getId() << setw(Bank::longestSurname) << u->getSurname() << setw(Bank::longestName) << u->getName() << ' ' << u->sum << '\n';
		u++;
	}
}

void getBankInfo(Bank bnk) {
	cout << "\nId:\t" << bnk.getId() << endl;

	cout << "Surname:\t" << bnk.getSurname() << endl;

	cout << "Name:\t" << bnk.getName() << endl;

	cout << "Deposit:\t" << bnk.sum << endl << endl;
}

void motd() {
	cout << "\n/////////////// What do you want to do?\n";
	cout << "Save DB to hard drive:                1\n";
	cout << "Show the DB:                          2\n";
	cout << "Add new account:                      3\n";
	cout << "Get account info:                     4\n";
	cout << "Find accounts with deposit more than: 5\n";
	cout << "Exit:                                 0\n";
	cout << "\nType a number: ";
}

void main() {
	Bank* db = (Bank*)calloc(1, sizeof(Bank));
	FILE* dbFile;
	int dbLen = 0;
	fopen_s(&dbFile, DBNAME, "a+");

	int except = 0;

	int longestName = 4;
	int longestSurname = 7;

	for (int i = 0; !feof(dbFile); i++) {
		dbLen++;
		db = (Bank*)realloc(db, dbLen * sizeof(Bank));

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

		db[i].defineBankAuto(bufName, bufSurname, bufSum);
	}
	fclose(dbFile);

	dbInfo(db);
	//cout << "DbLen: " << db[0].surname << endl;
	while (true) {
		motd();
		char var;
		cin >> var;

		bool found4 = false;
		double sum5 = 0;
		Bank newBank4;

		int id4 = -1;

		switch (var) {
		case '1':
			FILE * dbFile;

			fopen_s(&dbFile, DBNAME, "w");

			for (int i = 0; i < dbLen; i++)
			{
				fprintf(dbFile, "%ld ", (db[i].getId()));
				fprintf(dbFile, "%s ", db[i].getSurname(), MAXNAMELEN);// Было 15 вместо maxnamelen
				fprintf(dbFile, "%s ", db[i].getName(), MAXNAMELEN);
				fprintf(dbFile, "%lf", (db[i].sum));
				if (i != dbLen - 1) fprintf(dbFile, "\n");
			}
			fclose(dbFile);
			break;
		case '2':
			dbInfo(db, dbLen, longestName, longestSurname);
			break;
		case '3':
			dbLen++;
			db = (Bank*)realloc(db, dbLen * sizeof(Bank));

			

			cout << endl;

			newBank.defineBankManual();

			db[Bank().count - 1] = newBank;
			cout << "\nBank has been succesfully added to data base" << endl;
			break;

		case '4':
			cout << "Enter Surname: ";
			char surname4[MAXNAMELEN];
			cin >> surname4;
			cout << "Enter Name: ";
			char name4[MAXNAMELEN];
			cin >> name4;

			for (int i = 0; i < dbLen; i++) {
				if (strcmp(name4, db[i].name) == 0 && strcmp(surname4, db[i].surname) == 0) {
					found4 = true;
					getBankInfo(db[i]);
					break;
				}
			}

			if (!found4) cout << "Not found";

			break;
		case '5':
			cout << "Enter a number, accounts with deposit higher than it will be shown:" << endl;
			cin >> sum5;

			for (int i = 0; i < dbLen; i++)
			{
				if (db[i].sum > sum5) getBankInfo(db[i]);
			}
			break;
		case '0':
			for (int i = 0; i < dbLen; ++i) {
				delete[] db[i].name;
				delete[] db[i].surname;
			}
			free(db);
			return;
		default:
			cout << "Unexpected symbol, please try again\n";
			break;
		}
	}
}
