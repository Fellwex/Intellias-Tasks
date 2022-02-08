#include <iostream>
#include <ctime>
#include "Matrix.h"
#include "LogDuration.h"

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	
	LogDuration logger("Total work");

	Matrix a(10, 3), b(3, 2);
	FillMatrix(a);
	FillMatrix(b);
	a.Print(std::cout);
	std::cout << "\n";
	b.Print(std::cout);
	std::cout << "\n";
	Matrix c = a * b;
	c.Print(std::cout);

	a = a.Transpose();
	a.Print(std::cout);
}

