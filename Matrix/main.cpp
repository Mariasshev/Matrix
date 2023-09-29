#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS

#include "Matrix.h"
#include "A.h"
#include <iostream>
using namespace std;



int main() {
	Matrix<A>b(2,3);
	Matrix<A>c(2,3);
	cout << endl;

	b.randMatrix();
	c.randMatrix();
	cout << "Matrix c: ";
	c.Print();
	cout << "Matrix b: " << endl;
	b.Print();
	cout << "Max: ";
	//b.findMax();
	cout << "Min: ";
	//b.findMin();

	//check: matrix + num
	b + 10;
	b.Print();

	//check: matrix - num
	b - 5;
	b.Print();

	//check: matrix * num
	b * 5;
	b.Print();

	//check: matrix / num
	b / 3;
	b.Print();

	//check: matrix + matrix
	b + c;
	b.Print();

	//check: matrix - matrix
	b - c;
	b.Print();

	//check: matrix * matrix
	b * c;
	b.Print();

	//cout << b(2, 1);

}