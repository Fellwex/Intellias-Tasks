#include <iostream>
#include <ctime>
#include "Matrix.h"
#include "LogDuration.h"

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	LogDuration logger("Total program worked");

	Matrix a(15, 15), b(15, 15);
	FillMatrix(a);
	FillMatrix(b);

	std::cout << "Matrix A" << std::endl;
	a.Print(std::cout);
	std::cout << "\n";

	std::cout << "Matrix B" << std::endl;
	b.Print(std::cout);
	std::cout << "\n";

	{
		LogDuration logSumByRows("Operation SumByRows worked");
		int total = 0;
		for (int i = 0; i < a.GetRowsNumber(); ++i)
		{
			total += a.SumByRow(i);
		}
		std::cout << "Total sum by rows = " << total << "\n";
	}
	{
		LogDuration logSumByColumns("Operation SumByColumns worked");
		int total = 0;
		for (int i = 0; i < a.GetColumnsNumber(); ++i)
		{
			total += a.SumByColumn(i);
		}
		std::cout << "Total sum by columns = " << total << "\n";
	}
	std::cout << "\n";
	{
		LogDuration logTranspose("Operation Transpose worked");
		Matrix c = a.Transpose();
		c.Print(std::cout);
	}
	std::cout << "\n";
	{
		LogDuration logAdd("Operation + between matrixes worked");
		Matrix c = a + b;
		c.Print(std::cout);
	}
	std::cout << "\n";
	{
		LogDuration logSub("Operation - between matrixes worked");
		Matrix c = a - b;
		c.Print(std::cout);
	}
	std::cout << "\n";
	{
		LogDuration logMul("Operation * between matrixes worked");
		Matrix c = a * b;
		c.Print(std::cout);
	}
	return 0;
}

