#include<iostream>
#include<iomanip>
#include"Matrix.h"

using namespace std;

void Matrix::fillData() {
	data = new int* [rows];
	for (int i = 0; i < rows; i++) {
		data[i] = new int[columns];
		for (int j = 0; j < columns; j++) {
			data[i][j] = rand() % 21 - 10;
		}
	}
}

Matrix::Matrix() {
	rows = 5;
	columns = 5;
	fillData();
}

Matrix::Matrix(int rows, int columns) {
	this->rows = rows;
	this->columns = columns;
	fillData();
}

Matrix::~Matrix() {
	for (int i = 0; i < rows; i++) {
		delete[] data[i];
	}
	delete[] data;
}

void Matrix::display() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << setw(4) << data[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int Matrix::getElement(int i, int j) {
	return data[i][j];
}

void Matrix::setElement(int i, int j, int value) {
	data[i][j] = value;
}

int Matrix::getRows() {
	return rows;
}

int Matrix::getColumns() {
	return columns;
}

void sum(Matrix& mtr1, Matrix& mtr2, Matrix& res)
{
	if (mtr1.rows)

	for (int i = 0; i < mtr1.rows; i++) {
		for (int j = 0; j < mtr1.columns; j++) {
			res.setElement(i, j, mtr1.getElement(i, j) + mtr2.getElement(i, j));
		}

	}
}

void multiply(Matrix& mtr1, Matrix& mtr2, Matrix& res)
{
}
