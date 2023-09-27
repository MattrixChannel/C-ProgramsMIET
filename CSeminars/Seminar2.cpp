#include <iomanip>
#include <iostream>
#include <ctime>

using namespace std;
// Создать класс Матрица 2 поля: строки и столбцы
// двумерный динамический массив
// Конструктор
class Matrix {
	int rows;
	int columns;
	int** data;

	void fillData() {
		data = new int*[rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new int[columns];
			for (int j = 0; j < columns; j++) {
				data[i][j] = rand() % 21 - 10;
			}
		}
	}
public:
	Matrix() {
		rows = 5;
		columns = 5;
		fillData();
	}

	Matrix(int rows, int columns) {
		this->rows = rows;
		this->columns = columns;
		fillData();
	}

	~Matrix() {
		for (int i = 0; i < rows; i++) {
			delete[] data[i];
		}
		delete[] data;
	}

	void display() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << setw(4) << data[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}

	int getElement(int i, int j) {
		return data[i][j];
	}

	void setElement(int i, int j, int value) {
		data[i][j] = value;
	}

	int getRows() {
		return rows;
	}

	int getColumns() {
		return columns;
	}
};

int main()
{
	srand(time(0));

	Matrix mtrx(7, 7);

	mtrx.display();

	cout << mtrx.getElement(0, 0) << endl;

	mtrx.setElement(0, 0, 99);

	cout << mtrx.getElement(0, 0) << endl;

	mtrx.display();

	for (int i = 0; i < mtrx.getRows(); i++) {
		for (int j = 0; j < mtrx.getColumns(); j++) {
			//mtrx.setElement(i, j, 2 * (i + j) + 1);
		}
	}

	mtrx.display();

	for (int i = 0; i < mtrx.getRows() - 1; i++) {
		for (int j = i + 1; j < mtrx.getColumns(); j++) {
			cout << setw(4) << mtrx.getElement(i, j);
		}
		cout << endl;
	}

	mtrx.display();

	return 0;
}
