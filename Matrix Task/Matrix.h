#pragma once
#include <iostream>

class Matrix
{
public:
	Matrix();
	Matrix(int newRowsNumber, int newColumnsNumber);
	Matrix(const Matrix& anotherMatrix);
	Matrix& operator=(const Matrix& anotherMatrix);
	~Matrix();

	void Print(std::ostream& out) const;
	int GetRowsNumber() const;
	int GetColumnsNumber() const;
	int& At(int rowNumber, int columnNumber);
	int At(int rowNumber, int columnNumber) const;
	
	int SumByRow(int rowNumber) const;
	int SumByColumn(int columnNumber) const;
	Matrix Transpose() const;
private:
	int rows, columns;
	int* data;

	void CheckOutOfRange(int rowNumber, int columnNumber) const;
};

Matrix operator+(const Matrix& left, const Matrix& right);
Matrix operator-(const Matrix& left, const Matrix& right);
Matrix operator*(const Matrix& left, const Matrix& right);

void FillMatrix(Matrix& matrix);
