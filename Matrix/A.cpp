#include "A.h"

A::A()
{
	rows = cols = 0;
	arr = nullptr;
}

A::A(int r, int c)
{
	rows = r;
	cols = c;
	arr = new int* [rows];
	for (int i = 0; i < rows; i++) 
	{
		arr[i] = new int[cols];
	}
}

A::A(const A& obj)
{
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

int* A::operator[](int index)
{
	return arr[index];
}

int& A::operator()(int r, int c)
{
	return arr[r][c];
}

A& A::operator=(int a)
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

A& A::operator=(const A& obj)
{
	if (this != &obj)
	{
		return *this;
	}
	Delete();
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
			arr[i][j] = obj.arr[i][j];
		}
	}
	return *this;
}

void A::Delete()
{
	if (rows > 0) {
		for (int i = 0; i < rows; i++)
		{
			delete[] arr[i];
		}
	}
	if (cols > 0) {
		delete[]arr;
	}
}

ostream& operator<<(ostream& os, A& b) {
	for (int i = 0; i < b.rows; i++)
	{
		for (int j = 0; j < b.cols; j++)
		{
			os << b.arr[i][j] << ' ';
		}
		os << endl;
	}
	return os;
}
