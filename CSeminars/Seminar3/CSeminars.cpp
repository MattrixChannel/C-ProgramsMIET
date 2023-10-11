#include <iomanip>
#include <iostream>
#include <ctime>
#include "Matrix.h"

using namespace std;

int main()
{
	srand(time(0));

	Matrix mtrx1(7, 7);

	cout << "Matrix A:" << endl;
	mtrx1.display();
	cout << "\nA[0][0]: ";
	cout << mtrx1.getElement(0, 0) << endl;

	mtrx1.setElement(0, 0, 99);

	cout << "\nA[0][0]: ";
	cout << mtrx1.getElement(0, 0) << endl;

	cout << "Matrix A:" << endl;
	mtrx1.display();

	for (int i = 0; i < mtrx1.getRows(); i++) {
		for (int j = 0; j < mtrx1.getColumns(); j++) {
			mtrx1.setElement(i, j, 2 * (i + j) + 3);
		}
	}

	cout << "Matrix A:" << endl;
	mtrx1.display();

	Matrix mtrx2(7, 7);

	for (int i = 0; i < mtrx2.getRows(); i++) {
		for (int j = 0; j < mtrx2.getColumns(); j++) {
			mtrx2.setElement(i, j, 2 * (i - j) + 1);
		}
	}

	cout << "Matrix B:" << endl;
	mtrx2.display();

	Matrix res(7, 7);
	sum(mtrx1, mtrx2, res);


	cout << "Matrix A+B:" << endl;
	res.display();

	return 0;
}