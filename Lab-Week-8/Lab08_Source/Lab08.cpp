//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 3/14/19
// Project: Midterm Week 8
// Class: CS 201
//-----------------------------------------------------------------------------

#include "Lab08Utility.h"
#include <iostream>

int main() 
{
	// Initialize lists
	std::vector<float> dvdCosts;
	std::vector<float> musicCosts;
	std::vector<float> tvCosts;
	std::vector<Costs> allCosts;

	// Get file data and handle errors thrown
	try
	{
		GetData(dvdCosts, musicCosts, tvCosts, "input.txt");
	}
	catch (std::runtime_error error)
	{
		std::cout << error.what();
	}


	// Calculate DVD data 
	Costs allDVDCosts;
	allDVDCosts.type = "DVD";
	allDVDCosts.total = TotalCosts(dvdCosts);
	try
	{
		allDVDCosts.mean = MeanCosts(dvdCosts);
	}
	catch (std::runtime_error e)
	{
		allDVDCosts.mean = -1;
	}

	try
	{
		allDVDCosts.median = MedianCosts(dvdCosts);
	}
	catch (std::runtime_error e)
	{
		allDVDCosts.mean = -1;
	}

	allCosts.push_back(allDVDCosts);

	// Calculate TV data
	Costs allTVCosts;

	allTVCosts.type = "TV";
	allTVCosts.total = TotalCosts(tvCosts);
	try
	{
		allTVCosts.mean = MeanCosts(tvCosts);
	}
	catch (std::runtime_error e)
	{
		allTVCosts.mean = -1;
	}

	try
	{
		allTVCosts.median = MedianCosts(tvCosts);
	}
	catch (std::runtime_error e)
	{
		allTVCosts.mean = -1;
	}

	allCosts.push_back(allTVCosts);

	Costs allMusicCosts;

	//Calculate Music data
	allMusicCosts.type = "MUSIC";
	allMusicCosts.total = TotalCosts(musicCosts);
	try
	{
		allMusicCosts.mean = MeanCosts(musicCosts);
	}
	catch (std::runtime_error e)
	{
		allMusicCosts.mean = -1;
	}

	try
	{
		allMusicCosts.median = MedianCosts(musicCosts);
	}
	catch (std::runtime_error e)
	{
		allMusicCosts.mean = -1;
	}

	allCosts.push_back(allMusicCosts);

	// Print results of calculations
	PrintResults(allCosts);

	return 0;
}