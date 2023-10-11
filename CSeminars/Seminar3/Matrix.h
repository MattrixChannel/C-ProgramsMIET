#pragma once

class Matrix {
	int rows;
	int columns;
	int** data;

	void fillData();
public:
	Matrix();

	Matrix(int rows, int columns);

	~Matrix();

	void display();

	int getElement(int i, int j);

	void setElement(int i, int j, int value);

	int getRows();

	int getColumns();

	friend void sum(Matrix& mtr1, Matrix& mtr2, Matrix& res);

	friend void multiply(Matrix& mtr1, Matrix& mtr2, Matrix& res);
};