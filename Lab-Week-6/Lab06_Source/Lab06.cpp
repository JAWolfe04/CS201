//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 2/28/19
// Project: Lab 6
// Class: CS201
//-----------------------------------------------------------------------------

#include "Lab06Helper.h"
#include <iostream>

int main() 
{
	std::vector<Distances> distances;

	//Load file
	std::cout << "Loading file contents" << std::endl;
	distances = getFilecontents("input.txt");

	if (!distances.empty())
	{
		//Calculate distances
		std::cout << "Calculating distances" << std::endl;
		calcDistances(distances);

		//Create file
		std::cout << "Creating file" << std::endl;
		addToFile(distances, "output_sorted.txt");
	}

	return 0;
}