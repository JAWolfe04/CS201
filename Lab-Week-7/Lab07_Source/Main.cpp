//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 3/7/19
// Project: Lab 7 - Fuel Economy
// Class: CS 201
//-----------------------------------------------------------------------------
#include "EconomyHelper.h"
#include <iostream>
#include <conio.h>

int main()
{
	//Program loop
	while(true)
	{
		//Tank history
		std::vector<Economy::Tank> tanks;

		while (true)
		{
			//Individual tank
			Economy::Tank tank;

			//Get a valid milage for the tank keep looping until valid
			while (true)
			{
				try
				{
					tank.miles = Economy::GetMiles();
					break;
				}
				catch (std::runtime_error& exception)
				{
					std::cout << exception.what() << "\n";
				}
			}

			//Get a valid gallons for the tank keep looping until valid
			while (true)
			{
				try
				{
					tank.gallons = Economy::GetGallons();
					break;
				}
				catch (std::runtime_error& exception)
				{
					std::cout << exception.what() << "\n";
				}
			}

			//Add to tank history
			tanks.push_back(tank);

			//Check for another tank
			std::cout << "Enter another tank? Y/N ";

			//Get valid choice
			bool newTank = false;
			while (true)
			{
				char input;
				input = toupper(_getch());
				std::cout << "\n";

				if (input == 'Y')
				{
					newTank = true;
					break;
				}
				else if (input == 'N')
					break;
				else
					std::cout << "Invalid choice. Enter another tank? Y/N\n";
			}

			//Stop with this history if they do not want to enter a new tank
			if (!newTank)
				break;
		}

		//Print the MPG
		try 
		{
			std::cout << "Total mpg is " << Economy::GetMPG(tanks) << "\n\n";
		}
		catch (std::runtime_error& exception)
		{
			std::cout << exception.what() << "\n";
		}

		//Check if user wants to continue
		char input;
		while (true)
		{
			std::cout << "Press Q to quit or any other key to restart\n";
			input = toupper(_getch());

			if (input == 'Q')
			{
				return 0;
			}
			else
				break;
		}
	}
}