//-----------------------------------------------------------------------------
// Jonathan Wolfe
// Eamil: jawhf4@mail.umkc.edu
// Due: 2/21/19
// CS201L Lab 05
//-----------------------------------------------------------------------------

#include "MatrixMath.h"

#include <iostream>
#include <conio.h>

int main() 
{
	bool running = true;
	std::vector<std::vector<int>> matrix1;
	std::vector<std::vector<int>> matrix2;

	//Main program loop
	while (running)
	{
		//Create the first matrix and print it
		CreateMatrix(matrix1);

		std::cout << "\nYou entered the grid g1 as\n";
		PrintMatrix(matrix1);

		//Create the second matrix and print it
		CreateMatrix(matrix2);

		std::cout << "\nYou entered the grid g2 as\n";
		PrintMatrix(matrix2);

		//Add and multiply matrices and print results
		AddMatrices(matrix1, matrix2);

		MultiplyMatrices(matrix1, matrix2);

		//Prompt user for input and possibly end program if Q
		std::cout << "Press Q to quit, any other key to do another grid";
		if (toupper(_getch()) == 'Q')
		{
			running = false;
		}
		else
		{
			std::cout << "\n\n";
		}
	}

	return 0;
}