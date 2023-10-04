#include <iostream>
#include <iomanip>

#define MAXNAMELEN 30
#define DBNAME "save.txt"

using namespace std;


class Bank {
	int id;
	char* name;
	char* surname;

	friend void getBankInfo(Bank* bnk);
public:
	double sum;


	static int count;
	static int longestName;
	static int longestSurname;
	
	int getId() { return id; };
	void setId(int num) { id = num; };
	char* getSurname() { return surname; };
	char* getName() { return name; };

	Bank() {
		id = count+1;
		name = new char[MAXNAMELEN];
		strcpy_s(name, 12, "DefaultName");
		surname = new char[MAXNAMELEN];
		strcpy_s(surname, 15, "DefaultSurname");
		sum = 0;
		count++;
	}

	~Bank() {
		delete[] name;
		delete[] surname;
		count--;
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

	void getAccsWithDepositMoreThan(Bank* db, int summ) {
		for (int i = 0; i < Bank::count; i++)
		{
			if (db[i].sum > summ) getBankInfo(&db[i]);
		}
	}

	const void operator + (double num) {
		sum += num;
	}

	friend istream& operator>> (istream& is, Bank& bnk)
	{
		cout << "Surname: ";
		is >> bnk.name;
		cout << "Name: ";
		is >> bnk.surname;
		cout << "Deposit: ";
		is >> bnk.sum;
		return is;
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
	for (int i = 0; i < Bank::count; i++) {
		cout << setw(2) << u->getId() << setw(Bank::longestSurname + 1) << u->getSurname() << setw(Bank::longestName + 1) << u->getName() << ' ' << u->sum << '\n';
		u++;
	}
}

void getBankInfo(Bank* bnk) {
	cout << "\n" << setw(9) << "Id: " << bnk->id << endl;

	cout << setw(9) << "Surname: " << bnk->surname << endl;

	cout << setw(9) << "Name: " << bnk->name << endl;

	cout << setw(9) << "Deposit: " << bnk->sum << endl << endl;
}

void cpyDB(Bank* Don, Bank* Rec, int size) {
	for (int i = 0; i < size; i++) {
		Rec[i].defineBankAuto(Don[i].getName(), Don[i].getSurname(), Don[i].sum);
		Rec[i].setId(i + 1);
	}
	Rec[size].setId(size + 1);
}

Bank* expandDb(Bank* db) {
	int size = Bank::count;

	Bank* newDb = new Bank[size + 1];

	for (int i = 0; i < size; i++) {
		newDb[i].defineBankAuto(db[i].getName(), db[i].getSurname(), db[i].sum);
		newDb[i].setId(i + 1);
	}
	newDb[size].setId(size + 1);

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
	cout << "Add new accout (experimantal)         7\n";
	cout << "Exit:                                 0\n";
	cout << "\nType a number: ";
}

void main() {

	Bank* db = new Bank[1];
	FILE* dbFile;
	fopen_s(&dbFile, DBNAME, "a+");
	//cout << Bank::count;

	//cout << Bank::count;
	int except = 0;

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
		int num6 = 0;
		int id6 = 0;

		int id4 = -1;

		switch (var) {
		case '1':
			FILE * dbFile;

			fopen_s(&dbFile, DBNAME, "w");

			for (int i = 0; i < Bank::count; i++)
			{
				fprintf(dbFile, "%s ", db[i].getSurname(), MAXNAMELEN);// Было 15 вместо maxnamelen
				fprintf(dbFile, "%s ", db[i].getName(), MAXNAMELEN);
				fprintf(dbFile, "%lf", (db[i].sum));
				if (i != Bank::count - 1) fprintf(dbFile, "\n");
			}
			fclose(dbFile);
			break;
		case '2':
			dbInfo(db);
			break;
		case '3':
			//cout << Bank::count;

			db = expandDb(db);

			cout << endl;

			//cout << Bank::count << ' ' << db[0].getName();
			db[Bank::count-1].defineBankManual();

			cout << "\nBank has been succesfully added to data base" << endl;
			break;
			cout << Bank::count;
		case '4':
			cout << "Enter Surname: ";
			char surname4[MAXNAMELEN];
			cin >> surname4;
			cout << "Enter Name: ";
			char name4[MAXNAMELEN];
			cin >> name4;

			for (int i = 0; i < Bank::count; i++) {
				if (strcmp(name4, db[i].getName()) == 0 && strcmp(surname4, db[i].getSurname()) == 0) {
					found4 = true;
					getBankInfo(&db[i]);
					break;
				}
			}

			if (!found4) cout << "Not found";

			break;
		case '5':
			cout << "Enter a number, accounts with deposit higher than it will be shown:" << endl;
			cin >> sum5;

			db[0].getAccsWithDepositMoreThan(db, sum5);

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
			//cout << Bank::count;
			db = expandDb(db);

			cout << endl;

			//cout << Bank::count << ' ' << db[0].getName();
			cin >> db[Bank::count - 1];

			cout << "\nBank has been succesfully added to data base" << endl;

			break;
		case '0':
			//cout << Bank::count;
			delete[] db;
			return;
		default:
			cout << "Unexpected symbol, please try again\n";
			break;
		}
	}
}
