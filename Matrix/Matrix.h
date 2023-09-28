#pragma once
#include <iostream>
using namespace std;

template <class T>
class Matrix {
	T** matrix;
	int rows;
	int cols;
public:
	Matrix() {
		rows = cols = 0;
		matrix = nullptr;
	}
	Matrix(int r, int c) 
	{
		rows = r;
		cols = c;
		matrix = new T*[rows];
		for (int i = 0; i < rows; i++) {
			matrix[i] = new T[cols];
		}
		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < cols; j++) 
			{
				matrix[i][j] = 0;
			}
		}		
	}
	void InitMatrix() 
	{
		int r, c;
		cout << "Enter rows: ";
		cin >> r;
		rows = r;
		cout << "Enter cols: ";
		cin >> c;
		cols = c;

		matrix = new T * [rows];
		for (int i = 0; i < rows; i++) 
		{
			matrix[i] = new T[cols];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << "enter " << j + 1 << "col: ";
				cin >> matrix[i][j];
			}
		}
	}
	void Print() 
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	Matrix& operator = (int a)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				matrix[i][j] = a;
			}
		}
		return *this;
	}

	void randMatrix()
	{
		//rows = r;
		//cols = c;
		matrix = new T * [rows];
		for (int i = 0; i < rows; i++) {
			matrix[i] = new T[cols];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				 matrix[i][j] = rand() % 10;
			}
		}
	}

	Matrix operator=(const Matrix& obj)
	{
		if (rows > 0)
		{
			for (int i = 0; i < rows; i++)
				delete[] matrix[i];
		}
		if (cols > 0)
		{
			delete[] matrix;
		}
		rows = obj.rows;
		cols = obj.cols;
		matrix = new T * [rows];
		for (int i = 0; i < rows; i++) 
		{
			matrix[i] = new T[cols];
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) 
			{
				matrix[i][j] = obj[i][j];
			}
		}	
		return *this;
	}

	T findMax() {
		T max = matrix[0][0];
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (max < matrix[i][j]) {
					max = matrix[i][j];
				}
			}
			cout << endl;
		}
		return max;
	}

	T findMin() {
		T min = matrix[0][0];
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (min > matrix[i][j]) {
					min = matrix[i][j];
				}
			}
			cout << endl;
		}
		return min;
	}


	Matrix<T>& operator=(const Matrix& obj) {
		if (this != &obj)
		{
			return *this;
		}
		if (rows > 0) {
			for (int i = 0; i < rows; i++)
			{
				delete[] matrix[i];
			}
		}
		if (cols > 0) {
			delete[]matrix;
		}
		rows = obj.rows;
		cols = obj.cols;
		matrix = new int* [rows];
		for (int i = 0; i < rows; i++) {
			matrix[i] = new int[cols];
		}
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				matrix[i][j] = obj.matrix[i][j];
			}
		}
		return *this;
	}

	Matrix<T>operator+(const int num);		//matrix + num
	Matrix<T>operator-(const int num);		//matrix - num
	Matrix<T>operator*(const int num);		//matrix * num
	Matrix<T>operator/(const int num);		//matrix / num

	


	Matrix<T>operator+(const Matrix<T>& obj);						//matrix + matrix
	Matrix<T>operator-(const Matrix<T>& obj);						//matrix - matrix
	Matrix<T>operator*(const Matrix<T>& obj);						//matrix * matrix

	int* operator[](int index) {
		return matrix[index];
	}
	~Matrix() {
		if (rows > 0) {
			for (int i = 0; i < rows; i++) 
			{
				delete[] matrix[i];
			}
		}
		if (cols > 0) {
			delete[]matrix;
		}
	}
};

//matrix + num
template<class T>
inline Matrix<T> Matrix<T>::operator+(const int num)
{
	Matrix<T> rez(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			rez[i][j] = matrix[i][j] + num;
		}
	}
	return rez;
}


//matrix - num
template<class T>
inline Matrix<T> Matrix<T>::operator-(const int num)
{
	Matrix<T> rez(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			rez[i][j] = matrix[i][j] - num;
		}
	}
	return rez;
}


//matrix * num
template<class T>
inline Matrix<T> Matrix<T>::operator*(const int num)
{
	Matrix<T> rez(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			rez[i][j] = matrix[i][j] * num;
		}
	}
	return rez;
}


//matrix / num
template<class T>
inline Matrix<T> Matrix<T>::operator/(const int num)
{
	Matrix<T> rez(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			rez[i][j] = matrix[i][j] / num;
		}
	}
	return rez;
}

//matrix + matrix
template<class T>
inline Matrix<T> Matrix<T>::operator+(const Matrix<T>& obj)
{
	Matrix<T> rez(rows, cols);
	if (this->rows == obj.rows && this->cols == obj.cols) {
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				rez[i][j] = this->matrix[i][j] + obj.matrix[i][j];
			}
		}
	}
	else {
		cout << "Matrices have different size!" << endl;
	}
	return rez;
}

//matrix - matrix
template<class T>
inline Matrix<T> Matrix<T>::operator-(const Matrix<T>& obj)
{
	Matrix<T> rez(rows, cols);
	if (this->rows == obj.rows && this->cols == obj.cols) {
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				rez[i][j] = this->matrix[i][j] - obj.matrix[i][j];
			}
		}
	}
	else {
		cout << "Matrices have different size!" << endl;
	}
	return rez;
}

//matrix * matrix
template<class T>
inline Matrix<T> Matrix<T>::operator*(const Matrix<T>& obj)
{
	Matrix<T> rez(rows, cols);
	if (this->rows > obj.rows && this->cols > obj.cols) {
		//Matrix<T> rez(rows, cols);
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				rez[i][j] = this->matrix[i][j] * obj.matrix[i][j];
			}
		}
	}
	else if (this->rows < obj.rows && this->cols < obj.cols) {
		//Matrix<T> rez(obj.rows, obj.cols);
		for (int i = 0; i < obj.rows; i++)
		{
			for (int j = 0; j < obj.cols; j++)
			{
				rez[i][j] = obj.matrix[i][j] * this->matrix[i][j];
			}
		}
	}
	else {
		cout << "Matrices have different size!" << endl;
	}
	return rez;
}

//template<class T>
//inline bool Matrix<T>::operator!=(const Matrix<T>& obj)
//{
//	for (int i = 0; i < obj.rows; i++)
//	{
//		for (int j = 0; j < obj.cols; j++)
//		{
//			if (this->matrix[i][j] != obj.matrix[i][j]) {
//				break;
//				return true;
//			}
//			
//		}
//	}
//	return false;
//}

