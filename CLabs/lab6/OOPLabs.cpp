#include <iostream>
#include <vector>
#include <fstream>
#include "Student.h"
#include "Teacher.h"
#include <windows.h>

/*
1.	При оформлении ввода-вывода данных информация на экране должна быть отформатирована, согласно требованиям предыдущих лабораторных работ
2.	В данной лабораторной работе вы учитесь создавать проект без точных указаний по реализации базы данных. Такая постановка задачи называется работа по техническому заданию,
именно так работает программист в реальных условиях.
3.	В задании указан набор обязательных элементов проекта, но при реализации взаимодействия классов от вас потребуется добавить элементы:
•	необходимые для работы (счетчики, размеры массивов и т.п.);
•	не обязательные, но упрощающие реализацию алгоритмов обработки данных (для промежуточных данных, для хранения общих данных и т.п.)
•	вы также  можете усложнить иерархию и расширить интерфейсы в рамках поставленной задачи (это добавит вам баллы при защите работы).
4.	Общие требования к проекту:
•	Данные во всех классах должны быть защищенные (private или protected).
•	Обработка любых ошибок должна реализовываться в виде исключений
•	Данные, вносимые по ходу работы программы должны вводиться с клавиатуры, предусмотреть контроль корректности ввода и обработку ошибки. Например:
	контроль диапазона значений: 1-12(для месяца), 0-31 (для дня, )0-24(для часа), и т.п.;
	обработка ошибок при вычислениях, например запрет деления на ноль и т.п.

5.	В задании ничего не говориться о выводе информации на экран, но от решения этого вопроса зависит качество проекта в целом. В целом вывод можно разделить на три категории:
•	информация выводится по умолчанию при запуске программы;
•	информация выводится по запросу пользователя (пункт меню);
•	вывод информации – это результат выполнения какой-либо операции.
Обычно требуется использовать все три категории вывода. Должен быть пункт меню «распечатать всю информацию».

*/

void motd() {
	std::cout << "\n///////////////      Выберите цифру: \n";
	std::cout << "Сохранить на диск:                    1\n";
	std::cout << "Показать список:                      2\n";
	std::cout << "Добавить новую запись:                3\n";
	std::cout << "Получить информацию:                  4\n";
	std::cout << "Выход:                                0\n";
	std::cout << "\nЧисло: ";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	std::vector <Student> Students;
	std::vector <Teacher> Teachers;
	//std::cout << "Привет" << std::endl;

	//Student stud;
	//std::cout << stud.ToShortString() << std::endl;
	//Teacher tech;
	//std::cout << tech.ToShortString() << std::endl;

	//std::vector <Teacher> Teachers;
	//Teachers.push_back(Teacher(Man(), std::string("Физика"), spintex));

	//std::cout << Teachers[0].ToShortString() << " " << Teachers.size();

	const std::string dbFileName = "dbFile.txt";

	std::fstream dbFile;
	dbFile.open(dbFileName);

	std::string bufName;
	std::string bufSurname;
	std::string bufString;
	int bufInt;
	std::string type;

	if (dbFile.is_open()) {
		for (int i = 0; dbFile.good(); i++) {
			dbFile >> type;

			if (type == "S") {
				dbFile >> bufName >> bufSurname >> bufInt;
				Students.push_back(Student(Man(bufName, bufSurname), bufInt));
			}
			if (type == "T") {
				dbFile >> bufName >> bufSurname >> bufString >> bufInt;
				Teachers.push_back(Teacher(Man(bufName, bufSurname), bufString, static_cast<department>(bufInt)));
			}
		}
	}

	dbFile.close();

	Student::GetInfo(Students);
	std::cout << std::endl;
	Teacher::GetInfo(Teachers);
	/*
	std::string a;
	std::cin >> a;
	std::cout << a;*/
	//Man a;
	//std::cin >> a;
	//std::cout << a.ToShortString();
	/*
	std::string a = "";
	std::string b = "123a";
	std::string c = "asdawd";
	std::string d = "awgwe4adfa";
	std::string e = "54";
	std::cout << Common::has_number(a) << std::endl;
	std::cout << Common::has_number(b) << std::endl;
	std::cout << Common::has_number(c) << std::endl;
	std::cout << Common::has_number(d) << std::endl;
	std::cout << Common::has_number(e) << std::endl;
	//*/
	while (true) {
		motd();
		char var;
		std::cin >> var;
		std::string type3;
		std::string name3;
		std::string surname3;
		std::string string3;
		Teacher tech3;
		Student stud3;

		char type4;
		std::string name4;
		std::string surname4;
		Man Man4;
		bool found4 = false;

		try {
			switch (var) {
			case '1':
				dbFile.open(dbFileName);

				if (dbFile.is_open()) {
					for (int i = 0; i < Teachers.size(); i++) {
						dbFile << "T ";
						dbFile << Teachers[i].ToShortString();
						if (i != Teachers.size() - 1 || Students.size() != 0) dbFile << "\n";
					}

					for (int i = 0; i < Students.size(); i++) {
						dbFile << "S ";
						dbFile << Students[i].ToShortString();
						if (i != Students.size() - 1) dbFile << "\n";
					}
				}

				dbFile.close();
				break;

			case '2':
				Student::GetInfo(Students);
				std::cout << std::endl;
				Teacher::GetInfo(Teachers);
				break;

			case '3':

				std::cout << "Напишите T чтобы добавить учителя \nS чтобы добавить студента: ";
				std::cin >> type3;
				if (type3 == "T" || type3 == "Т") {
					std::cin >> tech3;
					Teachers.push_back(tech3);
					std::cout << "Запись успешно добавлена";
					break;
				}
				else if (type3 == "S") {
					std::cin >> stud3;
					Students.push_back(stud3);
					std::cout << "Запись успешно добавлена";
					break;
				}
				else {
					throw std::string{ "Неопознанный символ" };
					break;
				}
				break;

			case '4':
			{
				std::cin >> Man4;
				//std::cout << name4 << "\n";

				std::vector <Teacher> resultsT;
				for (int i = 0; i < Teachers.size(); i++) {
					if (Teachers[i] == Man4) {
						found4 = true;
						resultsT.push_back(Teacher());
						resultsT[resultsT.size() - 1] = Teachers[i];
					}
				}

				std::vector <Student> resultsS;
				for (int i = 0; i < Students.size(); i++) {
					if (Students[i] == Man4) {
						found4 = true;
						resultsS.push_back(Student());
						resultsS[resultsS.size() - 1] = Students[i];
					}
				}
				if (!found4) {
					std::cout << "\nРезультатов не найдено\n";
					break;
				}
				std::cout << "\nБыли найдены следущие результаты:\n";
				for (int i = 0; i < resultsS.size(); i++) {
					std::cout << resultsS[i] << std::endl;
				}
				for (int i = 0; i < resultsT.size(); i++) {
					std::cout << resultsT[i] << std::endl;
				}
			}
			break;

			case '0':
				//cout << Bank::count;
				
				return 0;
			default:
				throw std::string{ "Неопознанный символ" };
				break;
			}
		}
		catch (std::string e) {
			std::cout << e << std::endl;
		}
	}

	return 0;
}