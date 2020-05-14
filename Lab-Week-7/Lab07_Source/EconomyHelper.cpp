//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 3/7/19
// Project: Lab 7 - Fuel Economy
// Class: CS 201
//-----------------------------------------------------------------------------
#include "EconomyHelper.h"
#include <iostream>

double Economy::GetMiles()
{
	double miles;
	std::cout << "Enter the amount of miles on this tank: ";
	std::cin >> miles;

	//Handle none numbers
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		throw std::runtime_error("Invalid input received, you must enter a decimal number.");
	}
	//Handle less than 0
	else if (miles <= 0)
	{
		throw std::runtime_error("Miles cannot be less than or equal to 0.");
	}
	else
	{
		return miles;
	}
}

double Economy::GetGallons()
{
	double gallons;
	std::cout << "Enter the amount of gallons on this tank: ";
	std::cin >> gallons;

	//Handle none numbers
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		throw std::runtime_error("Invalid input received, you must enter a decimal number.");
	}
	//Handle less than 0
	else if (gallons <= 0)
	{
		throw std::runtime_error("Gallons cannot be less than or equal to 0.");
	}
	else
	{
		return gallons;
	}
}

double Economy::GetMPG(std::vector<Tank> tanks)
{
	double totalMiles = 0;
	double totalGallons = 0;

	//Sum miles and gallons
	for (unsigned int i = 0; i < tanks.size(); ++i)
	{
		totalMiles += tanks.at(i).miles;
		totalGallons += tanks.at(i).gallons;
	}

	return totalMiles / totalGallons;
}
