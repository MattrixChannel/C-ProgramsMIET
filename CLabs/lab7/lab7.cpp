#include <iostream>
#include <iomanip>
#include "Bank.h"
#include <string>
#include <fstream>
#include <list>

/*
1.	Используйте текст программы, реализованной в Л.Р.№3 для реализации программы в стиле STL, используя контейнеры, алгоритмы, итераторы.
2.	Перегрузить операторы, указанные в задании в стиле STL <----------------
3.	Использовать HDD для загрузки и сохранения данных
4.	Смотрите общие требования к предыдущим лабораторным работам, а именно
	Общие требования к выполнению заданий
	Пример распечатки данных в табличном виде
	Пример диалогового интерфейса
	Обязательные элементы для всех вариантов:
	загрузка данных с диска при запуске программы
	распечатка данных в табличном виде
	выход из программы с сохранением данных на диске
5.	В задании указаны методы, которые создаются обязательно, но как правило, для работы требуются и другие методы, какие – решать вам.
6.	Распечатывать как исходную информацию, так и результат.

*/

void dbInfo(std::list<Bank> db) {
	std::cout << "ID" << std::setw(Bank::longestSurname) << "Surname" << ' ' << std::setw(Bank::longestName) << "Name" << ' ' << "Debt" << std::endl;
	std::cout << "---------------------------------------------\n\n";
	for (auto u : db) {
		std::cout << std::setw(2) << u.getId() << std::setw(Bank::longestSurname + 1) << u.getSurname() << std::setw(Bank::longestName + 1) << u.getName() << ' ' << u.sum << '\n';

	}
}


void motd() {
	std::cout << "\n/////////////// What do you want to do?\n";
	std::cout << "Save DB to hard drive:                1\n";
	std::cout << "Show the DB:                          2\n";
	std::cout << "Add new account:                      3\n";
	std::cout << "Get account info:                     4\n";
	std::cout << "Delete front element:                 5\n";
	std::cout << "Add number to the deposit:            6\n";
	std::cout << "Sort by money descending              7\n";
	std::cout << "<< override demonstration             8\n";
	std::cout << "Exit:                                 0\n";
	std::cout << "\nType a number: ";
}

static int idST = 0;

bool findById(Bank b) {
	return b.getId() == idST;
}

bool SortBySum(const Bank& lhs, const Bank& rhs) {
	return lhs.sum > rhs.sum;
}

void main() {
	const std::string dbFileName = "save.txt";

	std::fstream dbFile;
	dbFile.open(dbFileName);

	int except = 0;

	std::string bufName;
	std::string bufSurname;
	double sum;

	std::list<Bank> db;

	if (dbFile.is_open()) {
		for (int i = 0; dbFile.good(); i++) {

			dbFile >> bufName >> bufSurname >> sum;
			//std::cout << bufName;
			db.push_back(Bank());
			db.back().defineBankAuto(bufName, bufSurname, sum);
			//std::cout << "+";
			Bank::count++;
		}
	}

	dbFile.close();
	dbInfo(db);
	//std::cout << "DbLen: " << db[0].surname << std::endl;
	while (true) {
		motd();
		char var;
		std::cin >> var;

		bool found4 = false;
		double sum5 = 0;
		int num6 = 0;
		int id6 = 0;

		int id4 = -1;

		switch (var) {
		case '1':
			dbFile.open(dbFileName);

			if (dbFile.is_open()) {
				for (auto elem : db) {
					dbFile << elem.ToString();
					if (!(elem == db.back())) dbFile << "\n";

				}
			}

			dbFile.close();
			break;
		case '2':
			dbInfo(db);
			break;
		case '3':
		{
			//std::cout << Bank::count;

			std::cout << std::endl;
			Bank b;
			Bank::count++;
			//std::cout << Bank::count << ' ' << db[0].getName();
			b.defineBankManual();


			std::cout << "Position: (0-" << Bank::count << ")\n";
			int buf;
			std::cin >> buf;

			std::list<Bank>::iterator it;
			it = db.begin();
			//insertObject(db, b, buf);
			
			if (buf >= 0 && buf < Bank::count) {
				std::advance(it, buf);
				db.insert(it, b);
			}
			else if (buf == Bank::count) {
				db.push_back(b);
			}
			else {
				std::cout << "Invalid id";
				Bank::count--;
				return;
			}
			
			std::cout << "\nBank has been succesfully added to data base" << std::endl;
			break;


		}
		
	case '4':
	{
		std::cout << "Enter ID: ";
		int buf;
		std::cin >> buf;

		idST = buf;

		auto res = std::find_if(db.begin(), db.end(), findById);

		if (res == db.end()) { std::cout << "Not found"; break;  }
		std::cout << res->ToString() << std::endl;

		break;
	}
	case '5':
		if (db.size() == 0) {
			std::cout << "List is empty\n";
			break;
		}
		db.pop_front();
		std::cout << "Done\n";
		break;
	case '6':
	{
		std::cout << "Enter ID: ";
		int buf;
		std::cin >> buf;

		idST = buf;

		auto res = std::find_if(db.begin(), db.end(), findById);

		if (res == db.end()) { std::cout << "Not found"; break; }

		std::cout << "Enter how much you want to add: ";
		double sum;
		std::cin >> sum;
		res->operator+(sum);

		std::cout << res->ToString() << std::endl;

		break;
	}
		
	case '7':
		db.sort(SortBySum);
		std::cout << "Done\n";
		break;
	case '8':
	{
		std::cout << db.front() << std::endl;
		break;
	}
		case '0':
			//std::cout << Bank::count;

			return;
		default:
			std::cout << "Unexpected symbol, please try again\n";
			break;
		}
	}
}