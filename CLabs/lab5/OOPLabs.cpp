#include <iostream>
#include <vector>
#include <fstream>
#include "Student.h"
#include "Teacher.h"

/*
Общие требования выполнения работы

1.	На первом этапе нужно создать проект программы.
В каждом задании описываются два родственных класса, из которых нужно создать иерархию из 3-х классов (базовый и два производных класса)
–	определите какие данные будут в базовом, а какие в производных классах
–	определите интерфейсы (методы) базового и производных классов, при реализации  используйте как методы класса, так и дружественные функции
–	cделайте виртуальными и переопределите в производных классах те методы, для   которых это целесообразно и возможно.

2.	Данные размещаются в динамической памяти. При желании можно использовать контейнер vector
3.	Ввод и вывод данных должен быть на русском языке
4.	Как и в предыдущих лабораторных работах должен использоваться диалоговый интерфейс для выбора действия
5.	При выполнении действия «выход из программы» нужно сохранить данные на диске
6.	При первом запуске программы ввод данных с клавиатуры, если программа уже запускалась, то данные загружаются из файла перед выходом на диалог.
7.	Обязательные функции для всех вариантов:
–	добавить новые элементы производных классов (ввод данных с клавиатуры)
–	распечатка данных в табличном виде
–	выход из программы с записью данных на диск
8.	 В классе должны быть все необходимые элементы для работы тестовой программы.


К   БДЗ предъявляются большие требования, чем к лабораторной работе.
Оценка проходит по 2 критериям:
1.	оценка проекта программы			  – 50%
2.	оценка реализации (сама программа)      – 50%
	Оформление ввода-вывода на экране
	Надежность работы программы (она должна работать с разнообразными данными, реагировать на ошибки оператора)
Защита БДЗ (ответы на вопросы, по требованию преподавателя – внесение небольших изменений в программу во время защиты)
*/

void motd() {
	std::cout << "\n///////////////      Выберите цифру: \n";
	std::cout << "Сохранить на диск:                    1\n";
	std::cout << "Показать список:                      2\n";
	std::cout << "Добавить новую запись:                3\n";
	std::cout << "Получить информацию:                  4\n";
	std::cout << "Testing                               7\n";
	std::cout << "Выход:                                0\n";
	std::cout << "\nЧисло: ";
}

int main() {
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
	department bufDep;
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

	std::cout << Teachers[0].ToShortString() << std::endl << Teachers[1].ToShortString() << std::endl;

	while (false) {
		motd();
		char var;
		std::cin >> var;
		std::string type3;
		std::string name3;
		std::string surname3;
		std::string string3;
		int num3;


		switch (var) {
		case '1':

			break;

		case '2':
			break;

		case '3':
			std::cout << "Напишите T чтобы добавить учителя \nS чтобы добавить студента: ";
			std::cin >> type3;
			if (type3 == "T" || type3 == "Т") {
				std::cout << "Введите имя: ";
				std::cin >> name3;
				std::cout << "Введите фамилию: ";
				std::cin >> surname3;
				std::cout << "Введите преподаваемый курс: ";
				std::cin >> string3; 
				std::cout << "Введите кафедру (0 = spintex, 1 = bms, 2 = pkims): ";
				std::cin >> num3;// spintex, bms, pkims
				Teachers.push_back(Teacher(Man(name3, surname3), string3, static_cast<department>(num3)));
				std::cout << "Запись успешно добавлена";
				break;
			}
			else if (type3 == "S") {
				std::cout << "Введите имя: ";
				std::cin >> name3;
				std::cout << "Введите фамилию: ";
				std::cin >> surname3;
				std::cout << "Введите номер группы: ";
				std::cin >> num3;// spintex, bms, pkims
				Students.push_back(Student(Man(name3, surname3), num3));
				std::cout << "Запись успешно добавлена";
				break;
			}
			else {
				std::cout << "Неизвестный символ";
				break;
			}
			break;

		case '4':

			break;

		case '5':

			break;

		case '6':

			break;

		case '7':

			break;

		case '0':
			//cout << Bank::count;

			return 0;
		default:
			std::cout << "Неопознанный символ\n";
			break;
		}
	}

	return 0;
}