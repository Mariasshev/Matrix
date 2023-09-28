#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS

#include "Matrix.h"
#include <iostream>
using namespace std;

class A {
	int** arr;
	int rows;
	int cols;
public:

	A() {
		rows = cols = 0;
		arr = nullptr;
	}
	A(int r, int c) {
		rows = r;
		cols = c;
		arr = new int* [rows];
		for (int i = 0; i < rows; i++) {
			arr[i] = new int[cols];
		}
	}
	A(const A& obj) {
		rows = obj.rows;
		cols = obj.cols;
		arr = new int* [rows];
		for (int i = 0; i < rows; i++) {
			arr[i] = new int[cols];
		}
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				this->arr[i][j] = obj.arr[i][j];
			}
		}
	}

	int* operator[](int index) {
		return arr[index];
	}


	//matrix + num
	A operator+(const int num)
	{
		A rez(rows, cols);
		arr = new int* [rows];
		for (int i = 0; i < rows; i++) {
			arr[i] = new int[cols];
		}
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				rez[i][j] += num;
			}
		}
		return rez;
	}

	//matrix - num
	A operator-(const int num)
	{
		A rez(rows, cols);
		arr = new int* [rows];
		for (int i = 0; i < rows; i++) {
			arr[i] = new int[cols];
		}
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				rez[i][j] -= num;
			}
		}
		return rez;
	}

	//matrix * num
	A operator*(const int num)
	{
		A rez(rows, cols);
		arr = new int* [rows];
		for (int i = 0; i < rows; i++) {
			arr[i] = new int[cols];
		}
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				rez[i][j] *= num;
			}
		}
		return rez;
	}

	//matrix / num
	A operator/(const int num)
	{
		A rez(rows, cols);
		arr = new int* [rows];
		for (int i = 0; i < rows; i++) {
			arr[i] = new int[cols];
		}
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				rez[i][j] /= num;
			}
		}
		return rez;
	}

	//matrix + matrix
	A operator+(const A& obj)
	{
		A rez(rows, cols);
		arr = new int* [rows];
		for (int i = 0; i < rows; i++) {
			arr[i] = new int[cols];
		}
		if (this->rows == obj.rows && this->cols == obj.cols) {
			for (int i = 0; i < this->rows; i++)
			{
				for (int j = 0; j < this->cols; j++)
				{
					rez[i][j] = arr[i][j] + obj.arr[i][j];
				}
			}
		}
		else {
			cout << "Matrices have different size!" << endl;
		}
		return rez;
	}

	//matrix - matrix
	A& operator-(const A& obj)
	{
		A rez(rows, cols);
		arr = new int* [rows];
		for (int i = 0; i < rows; i++) {
			arr[i] = new int[cols];
		}
		if (this->rows == obj.rows && this->cols == obj.cols) {
			for (int i = 0; i < this->rows; i++)
			{
				for (int j = 0; j < this->cols; j++)
				{
					rez[i][j] = arr[i][j] - obj.arr[i][j];
				}
			}
		}
		else {
			cout << "Matrices have different size!" << endl;
		}
		return rez;
	}

	//matrix * matrix
	A& operator*(const A& obj)
	{
		A rez(rows, cols);
		arr = new int* [rows];
		for (int i = 0; i < rows; i++) {
			arr[i] = new int[cols];
		}
		if (this->rows > obj.rows && this->cols > obj.cols) {

			for (int i = 0; i < this->rows; i++)
			{
				for (int j = 0; j < this->cols; j++)
				{
					rez[i][j] = this->arr[i][j] * obj.arr[i][j];
				}
			}
		}
		else if (this->rows < obj.rows && this->cols < obj.cols) {
			for (int i = 0; i < obj.rows; i++)
			{
				for (int j = 0; j < obj.cols; j++)
				{
					rez[i][j] = obj.arr[i][j] * arr[i][j];
				}
			}
		}
		else {
			cout << "Matrices have different size!" << endl;
		}
		return rez;
	}
	int& operator() (int r, int c)
	{
		return arr[r][c];
	}

	int GetMatrix() {
		return **arr;
	}
	void SetMatrix(int r, int c) {
		rows = r;
		cols = c;
		arr = new int* [rows];
		for (int i = 0; i < rows; i++) {
			arr[i] = new int[cols];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i][j] = rand() % 10;
			}
		}
	}

	A& operator = (int a)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i][j] = a;
			}
		}
		return *this;
	}

	/*A& operator=(const A& obj) {
		if (this != &obj) 
		{
			return *this;
		}
		if (rows > 0) {
			for (int i = 0; i < rows; i++)
			{
				delete[] arr[i];
			}
		}
		if (cols > 0) {
			delete[]arr;
		}
		rows = obj.rows;
		cols = obj.cols;
		arr = new int * [rows];
		for (int i = 0; i < rows; i++) {
			arr[i] = new int[cols];
		}
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				arr[i][j] = obj.arr[i][j];
			}
		}
		return *this;
	}*/
	int GetRows() {
		return rows;
	}
	int GetCols() {
		return cols;
	}
	int** GetArr() {
		return arr;
	}

	
};

ostream& operator<<(ostream& os, A& b)
{
	for (int i = 0; i < b.GetRows(); i++)
	{
		for (int j = 0; j < b.GetCols(); j++)
		{
			os << b.GetArr()[i][j] << ' ';
		}
		os << endl;
	}
	return os;
}

istream& operator>>(istream& is, A& obj)
{
	int row, col;
	is >> row >> col;
	obj.SetMatrix(row, col);
	return is;
}

int main() {
	Matrix<A>b(2,3);
	cout << endl;
	b.randMatrix();
	cout << "Matrix b: " << endl;
	b.Print();
	//cout << "Max: " << b.findMax() << endl;
	//cout << "Min: " << b.findMin() << endl;
	b + 10;
	b.Print();
	//b + c;
	//b.Print();

	//cout << b(2, 1);

}