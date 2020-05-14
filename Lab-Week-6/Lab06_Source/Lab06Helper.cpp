//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 2/28/19
// Project: Lab 6
// Class: CS201
//-----------------------------------------------------------------------------

#include "Lab06Helper.h"
#include <fstream>
#include <iostream>

std::vector<Distances> getFilecontents(const char* fileName)
{
	std::ifstream inFS(fileName);
	std::vector<Distances> fileContents;

	//Check if file is open
	if (!inFS.is_open())
	{
		std::cout << "Cannot load file" << std::endl;
	}
	else
	{
		//Get file contents
		while (!inFS.eof())
		{
			Distances dis1;
			Distances dis2;

			inFS >> dis1.x >> dis1.y >> dis1.z >> dis2.x >> dis2.y >> dis2.z;

			fileContents.push_back(dis1);
			fileContents.push_back(dis2);
		}
	}

	inFS.close();
	return fileContents;
}

void addToFile(std::vector<Distances>& dis, const char* fileName)
{
	std::ofstream outFS(fileName);

	//Add each entry in vector to file
	for (int i = 0; i < dis.size(); ++i)
	{
		outFS << dis.at(i).length << " ";
	}

	outFS.close();
}

void calcDistances(std::vector<Distances>& dis)
{
	//Loop through the vector, every other entry
	for (int i = 0; i < dis.size() - 1; i = i + 2)
	{
		//Calculate x, y and z powers
		double powX = std::pow(dis.at(i).x - dis.at(i + 1).x, 2);
		double powY = std::pow(dis.at(i).y - dis.at(i + 1).y, 2);
		double powZ = std::pow(dis.at(i).z - dis.at(i + 1).z, 2);
		double calDis = std::sqrt(powX + powY + powZ);

		//Add to vectors for the two points
		dis.at(i).length = calDis;
		dis.at(i + 1).length = calDis;
	}
	sortDistances(dis);
}

void sortDistances(std::vector<Distances>& dis)
{
	int i, j;
	double key;
	
	for (int i = 1; i < dis.size(); i++)
	{
		key = dis.at(i).length;
		j = i - 1;

		while (j >= 0 && dis.at(j).length > key)
		{
			dis.at(j + 1).length = dis.at(j).length;
			j = j - 1;
		}
		dis.at(j + 1).length = key;
	}
}
