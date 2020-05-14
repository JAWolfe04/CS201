//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 3/14/19
// Project: Midterm Week 8
// Class: CS 201
//-----------------------------------------------------------------------------

#include "Lab08Utility.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void GetData(std::vector<float>& DVD, std::vector<float>& Music, std::vector<float>& TV, std::string fileName)
{
	std::ifstream inFS;
	inFS.open(fileName);

	//Handle file not found
	if (inFS.fail())
	{
		inFS.close(); // Close to be safe, may not need
		throw std::runtime_error("Cannot open file\n");
	}

	while (!inFS.eof())
	{
		std::string mediaType;
		inFS >> mediaType;

		if (mediaType == "DVD")
		{
			float dvdCost;
			inFS >> dvdCost;

			// Handle invalid cost
			if (inFS.fail())
				throw std::runtime_error("Cannot read dvd cost from file");

			DVD.push_back(dvdCost);
		}
		else if (mediaType == "TV")
		{
			float tvCost;
			inFS >> tvCost;

			// Handle invalid cost
			if (inFS.fail())
				throw std::runtime_error("Cannot read tv cost from file");

			TV.push_back(tvCost);
		}
		else if (mediaType == "MUSIC")
		{
			float musicCost;
			inFS >> musicCost;

			// Handle invalid cost
			if (inFS.fail())
				throw std::runtime_error("Cannot read music cost from file");

			Music.push_back(musicCost);
		}
		// Handle unexpected media types
		else
		{
			throw std::runtime_error("Cannot read media type from file");
		}
	}
	inFS.close();
}

void InsertSort(std::vector<float>& list)
{
	for (int i = 1; i < list.size(); ++i) 
	{
		int j = i;		
		while (j > 0 && list.at(j) < list.at(j - 1)) 
		{
			//Swap values
			float temp = list.at(j);
			list.at(j) = list.at(j - 1);
			list.at(j - 1) = temp;
			--j;
		}
	}
}

float TotalCosts(std::vector<float>& list)
{
	float total = 0;

	//Sum up list data
	for (int i = 0; i < list.size(); ++i)
	{
		total += list.at(i);
	}

	return total;
}

float MeanCosts(std::vector<float>& list)
{
	// Handles empty list
	if (list.size() == 0)
		throw std::runtime_error("Media list does not contain any values");

	// Find total
	float total = 0;

	for (int i = 0; i < list.size(); ++i)
	{
		total += list.at(i);
	}

	// Return mean of list
	return total / list.size();
}

float MedianCosts(std::vector<float>& list)
{
	// Sort list
	InsertSort(list);

	// Handle empty list
	if (list.size() == 0)
		throw std::runtime_error("Media list does not contain any values");

	// Handle even sized list
	if (list.size() % 2 == 0)
	{
		// Get two middle numbers
		float lowerMid = list.at((list.size() / 2) - 1);
		float upperMid = list.at(list.size() / 2);

		// Return average of two middle numbers
		return (lowerMid + upperMid) / 2;
	}
	// Handle odd sized list
	else
	{
		// Return middle number
		return list.at(list.size() / 2);
	}
}

void PrintResults(std::vector<Costs>& list)
{
	std::cout << "Type \tTotal \tMedian \tMean\n";
	for (int i = 0; i < list.size(); ++i)
	{
		// Print data
		float median = list.at(i).median;
		float mean = list.at(i).mean;
		std::cout << list.at(i).type << '\t' << list.at(i).total << '\t';

		// Handle medians with no values
		if (median < 0)
			std::cout << "nan" << '\t';
		else
			std::cout << median << '\t';

		// Handle means with no values
		if(mean < 0)
			std::cout << "nan" << '\n';
		else
			std::cout << mean << '\n';
	}
}
