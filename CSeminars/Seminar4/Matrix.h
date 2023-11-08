#pragma once

class Matrix {
	int rows;
	int columns;
	int** data;

	void fillData();
public:
	Matrix();

	Matrix(int rows, int columns);

	Matrix(const Matrix& cop);

	~Matrix();

	void display();

	int getElement(int i, int j) const;

	void setElement(int i, int j, int value);

	int getRows() const;

	int getColumns() const;

	friend void sum(Matrix& mtr1, Matrix& mtr2, Matrix& res);

	friend void multiply(Matrix& mtr1, Matrix& mtr2, Matrix& res);

	Matrix operator+(const Matrix& other);
	Matrix operator-(const Matrix& other);
};