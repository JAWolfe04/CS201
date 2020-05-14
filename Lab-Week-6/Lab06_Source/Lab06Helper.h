//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 2/28/19
// Project: Lab 6
// Class: CS201
//-----------------------------------------------------------------------------

#pragma once
#include <vector>

//Holds node info of x, y, z and length to next node
struct Distances
{
	double x;
	double y;
	double z;
	double length;
};

//Gets the contents of the file and returns them
std::vector<Distances> getFilecontents(const char* fileName);

//Calculates the distances of accompanying nodes
void calcDistances(std::vector<Distances>& distances);

//Adds distances lengths to fileName
void addToFile(std::vector<Distances>& distances, const char* fileName);

//Sorts distances in ascending order
void sortDistances(std::vector<Distances>& distances);