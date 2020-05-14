//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 3/7/19
// Project: Lab 7 - Fuel Economy
// Class: CS 201
//-----------------------------------------------------------------------------
#pragma once
#include <vector>

namespace Economy
{
	struct Tank
	{
		double miles;
		double gallons;
	};

	/*PRE: None 
	POST: Returns the amount of miles from the tank. 
	I/O: Screen/keyboard . 
	USER INTERACTION:  Prompts for miles from tank number. 
	ERROR HANDLING: Throws runtime error if the user does not enter a number or a negative number. */
	double GetMiles();

	/*PRE: None
	POST: Returns the amount of gallons from the tank.
	I/O: Screen/keyboard .
	USER INTERACTION:  Prompts for gallons from tank number.
	ERROR HANDLING: Throws runtime error if the user does not enter a number or a negative number. */
	double GetGallons();

	/*PRE: tanks is a history of tanks
	POST: Returns the average miles per gallon from tanks.
	I/O: None.
	USER INTERACTION: None.
	ERROR HANDLING: None. */
	double GetMPG(std::vector<Tank> tanks);
}