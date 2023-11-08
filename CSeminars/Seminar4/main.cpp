#include <iostream>
#include "Matrix.h"

int main() {
	srand(time(0));
	Matrix matr1;
	Matrix matr2;

	Matrix c = matr1 + matr2;

	//matr1.display();
	matr1.display();
	matr2.display();
	c.display();

	return 0;
}
