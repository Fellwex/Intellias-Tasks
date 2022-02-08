#include "Matrix.h"
#include <stdexcept>

Matrix::Matrix() : rows(0), columns(0), data(nullptr)
{

}

Matrix::Matrix(int newRowsNumber, int newColumnsNumber) 
{
	if (newRowsNumber < 0 || newColumnsNumber < 0)
	{
		rows = columns = 0;
		data = nullptr;
	}
	else
	{
		rows = newRowsNumber;
		columns = newColumnsNumber;
		data = new int[rows * columns]();
	}
}

Matrix::Matrix(const Matrix& anotherMatrix) 
	: rows(anotherMatrix.rows), columns(anotherMatrix.columns),
	data(new int[rows * columns]())
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			int index = i * columns + j;
			*(data + index) = *(anotherMatrix.data + index);
		}
	}
}

Matrix& Matrix::operator=(const Matrix& anotherMatrix)
{
	if (this == &anotherMatrix)
	{
		return *this;
	}

	if (rows != anotherMatrix.rows || columns != anotherMatrix.columns)
	{
		delete[] data;

		rows = anotherMatrix.rows;
		columns = anotherMatrix.columns;
		data = new int[rows * columns]();
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			int index = i * columns + j;
			*(data + index) = *(anotherMatrix.data + index);
		}
	}
	return *this;
}

Matrix::~Matrix()
{
	delete[] data;
}

void Matrix::Print(std::ostream& out) const
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			int index = i * columns + j;
			out << *(data + index) << "\t";
		}
		out << "\n";
	}
}

int Matrix::GetRowsNumber() const
{
	return rows;
}

int Matrix::GetColumnsNumber() const
{
	return columns;
}

int& Matrix::At(int rowNumber, int columnNumber)
{
	CheckOutOfRange(rowNumber, columnNumber);
	int index = rowNumber * columns + columnNumber;
	return *(data + index);
}

int Matrix::At(int rowNumber, int columnNumber) const
{
	CheckOutOfRange(rowNumber, columnNumber);
	int index = rowNumber * columns + columnNumber;
	return *(data + index);
}

int Matrix::SumByRow(int rowNumber) const
{
	if (rowNumber < 0 || rowNumber >= rows)
	{
		throw std::out_of_range("Incorrect index");
	}

	int sum = 0;
	for (int i = 0; i < columns; ++i)
	{
		sum += *(data + rowNumber * columns + i);
	}
	return sum;
}

int Matrix::SumByColumn(int columnNumber) const
{
	if (columnNumber < 0 || columnNumber >= columns)
	{
		throw std::out_of_range("Incorrect index");
	}

	int sum = 0;
	for (int i = 0; i < rows; ++i)
	{
		sum += *(data + columnNumber + i * columns);
	}
	return sum;
}

Matrix Matrix::Transpose() const
{
	Matrix matrix(columns, rows);

	for (int i = 0; i < rows; ++i) 
	{
		for (int j = 0; j < columns; ++j)
		{
			matrix.At(j, i) = *(data + i * columns + j);
		}
	}
	return matrix;
}

void Matrix::CheckOutOfRange(int rowNumber, int columnNumber) const
{
	if (rowNumber < 0 || columnNumber < 0
		|| rowNumber >= rows || columnNumber >= columns)
	{
		throw std::out_of_range("Number of rows or number of columns is out of range");
	}
}

Matrix operator+(const Matrix& left, const Matrix& right)
{
	if (left.GetRowsNumber() != right.GetRowsNumber()
		|| left.GetColumnsNumber() != right.GetColumnsNumber())
	{
		throw std::invalid_argument("The matrixes have different size");
	}

	Matrix result(left.GetRowsNumber(), left.GetColumnsNumber());

	for (int i = 0; i < result.GetRowsNumber(); i++)
	{
		for (int j = 0; j < result.GetColumnsNumber(); j++)
		{
			result.At(i, j) = left.At(i, j) + right.At(i, j);
		}
	}

	return result;
}

Matrix operator-(const Matrix& left, const Matrix& right)
{
	if (left.GetRowsNumber() != right.GetRowsNumber()
		|| left.GetColumnsNumber() != right.GetColumnsNumber())
	{
		throw std::invalid_argument("The matrixes have different size");
	}

	Matrix result(left.GetRowsNumber(), left.GetColumnsNumber());

	for (int i = 0; i < result.GetRowsNumber(); i++)
	{
		for (int j = 0; j < result.GetColumnsNumber(); j++)
		{
			result.At(i, j) = left.At(i, j) - right.At(i, j);
		}
	}

	return result;
}

Matrix operator*(const Matrix& left, const Matrix& right)
{
	if (left.GetColumnsNumber() != right.GetRowsNumber())
	{
		throw std::invalid_argument("The matrixes have different size");
	}

	Matrix result(left.GetRowsNumber(), right.GetColumnsNumber());
	
	for (int i = 0; i < left.GetRowsNumber(); ++i)
	{
		for (int j = 0; j < right.GetColumnsNumber(); ++j)
		{
			for (int k = 0; k < left.GetColumnsNumber(); ++k)
			{
				result.At(i, j) += left.At(i, k) * right.At(k, j);
			}
		}
	}

	return result;
}

void FillMatrix(Matrix& matrix)
{
	for (int i = 0; i < matrix.GetRowsNumber(); ++i)
	{
		for (int j = 0; j < matrix.GetColumnsNumber(); ++j)
		{
			matrix.At(i, j) = rand() % 10;
			//std::cin >> matrix.At(i, j);
		}
	}
}
