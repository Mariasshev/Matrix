#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS

#include "Matrix.h"
#include "A.h"
#include <iostream>
using namespace std;



int main() {
	Matrix<A>b(2,3);
	cout << endl;
	b.randMatrix();
	cout << "Matrix b: " << endl;
	b.Print();
	//cout << "Max: " << b.findMax() << endl;
	//cout << "Min: " << b.findMin() << endl;
	//b + 10;
	b.Print();
	//b + c;
	//b.Print();

	//cout << b(2, 1);

}