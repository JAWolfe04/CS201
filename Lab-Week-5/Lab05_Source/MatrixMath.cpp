#include "MatrixMath.h"

#include <iostream>

int GetInInt()
{
	int input;

	while (true)
	{
		std::cin >> input;

		//Make sure the user enters a number
		if (!std::cin.fail())
		{
			//Make sure user enters a positive value
			if (input > 0)
			{
				return input;
			}
			else
			{
				//Clean buffer
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cout << "Invalid entry: please enter a number greater than 0.\n";
			}
		}
		else
		{
			//Clean buffer
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Invalid entry: please enter a number.\n";
		}
	}
}

void CreateMatrix(std::vector<std::vector<int>>& matrix)
{
	int colSize, rowSize;

	//Prompt for input
	std::cout << "Enter the number of rows in this matrix >> ";
	rowSize = GetInInt();

	std::cout << "\nEnter the number of columns in this matrix >> ";
	colSize = GetInInt();

	//Initialize matrix with row and ColSize
	matrix.resize(rowSize);
	for (int row = 0; row < rowSize; ++row)
	{
		matrix.at(row).resize(colSize);
	}

	//Prompt and populate matrix
	std::cout << "\nPlease enter the values in this matrix, " <<
		"you can enter each row at once, each cell or all of them separated by spaces.\n";

	for (int row = 0; row < rowSize; ++row)
	{
		for (int col = 0; col < colSize; ++col)
		{
			std::cin >> matrix.at(row).at(col);
		}
	}
}

void PrintMatrix(std::vector<std::vector<int>>& matrix)
{
	int rowSize = static_cast<int>(matrix.size());
	int colSize = static_cast<int>(matrix.at(0).size());

	for (int row = 0; row < rowSize; ++row)
	{
		for (int col = 0; col < colSize; ++col)
		{
			if (col == colSize - 1)
			{
				//Print entry and at the last column start a new row
				std::cout << matrix.at(row).at(col) << '\n';
			}
			else
			{
				//Print entry and space between entries
				std::cout << matrix.at(row).at(col) << " ";
			}
		}
	}

	std::cout << std::endl;
}

void AddMatrices(std::vector<std::vector<int>>& matrix1, std::vector<std::vector<int>>& matrix2)
{
	//Check if the matrices are the same size
	if (matrix1.size() == matrix2.size() && matrix1.at(0).size() == matrix2.at(0).size())
	{
		std::cout << "g1 + g2 is\n";

		for (int row = 0; row < matrix1.size(); ++row)
		{
			for (int col = 0; col < matrix1.at(0).size(); ++col)
			{
				if (col == matrix1.at(0).size() - 1)
				{
					std::cout << matrix1.at(row).at(col) + matrix2.at(row).at(col) << '\n';
				}
				else
				{
					std::cout << matrix1.at(row).at(col) + matrix2.at(row).at(col) << " ";
				}
			}
		}

		std::cout << "\n\n";
	}
	//Handle cases where matrices cannot be added
	else
	{
		std::cout << "Cannot add 2 grids of this size together, the # of rows and columns in each must be the same.\n\n";
	}
}

void MultiplyMatrices(std::vector<std::vector<int>>& matrix1, std::vector<std::vector<int>>& matrix2)
{
	if (matrix1.size() == matrix2.at(0).size())
	{
		std::cout << "g1 * g2 is\n";

		//Loop through matrix 1 rows
		for (int n = 0; n < matrix1.size(); ++n)
		{
			//Loop through matrix 2 columns
			for (int col = 0; col < matrix2.at(0).size(); ++col)
			{
				int sum = 0;
				//Loop through matrix 2 rows
				for (int row = 0; row < matrix2.size(); ++row)
				{
					sum += matrix1.at(n).at(row) * matrix2.at(row).at(col);
				}
				
				//Print summed entry
				if (col == matrix2.at(0).size() - 1)
				{
					std::cout << sum << '\n';
				}
				else
				{
					std::cout << sum << " ";
				}
			}
		}

		std::cout << '\n';
	}
	//Handle cases where matrices cannot be multiplied
	else
	{
		std::cout << "Cannot multiply 2 grids of this size together, " <<
			"the # of columns in grid 1 must be the same as the # of rows in grid 2.\n\n";
	}
}