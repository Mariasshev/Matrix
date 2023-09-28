#pragma once
#include "Matrix.h"
#include <iostream>
using namespace std;

class A {
	int** arr;
	int rows;
	int cols;
public:

	A();
	A(int r, int c);

	A(const A& obj); 

	int* operator[](int index);


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
				rez.arr[i][j] += num;
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
				rez.arr[i][j] -= num;
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
				rez.arr[i][j] *= num;
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
				rez.arr[i][j] /= num;
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
					rez.arr[i][j] = this->arr[i][j] + obj.arr[i][j];
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
					rez.arr[i][j] = this->arr[i][j] - obj.arr[i][j];
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
					rez.arr[i][j] = this->arr[i][j] * obj.arr[i][j];
				}
			}
		}
		else if (this->rows < obj.rows && this->cols < obj.cols) {
			for (int i = 0; i < obj.rows; i++)
			{
				for (int j = 0; j < obj.cols; j++)
				{
					rez.arr[i][j] = obj.arr[i][j] * this->arr[i][j];
				}
			}
		}
		else {
			cout << "Matrices have different size!" << endl;
		}
		return rez;
	}
	int& operator() (int r, int c);

	A& operator = (int a);

	A& operator=(const A& obj);
	void Delete();
	friend ostream& operator<<(ostream& os, A& b);
};

