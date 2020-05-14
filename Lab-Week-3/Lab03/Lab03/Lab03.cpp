//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 2/7/2019
//-----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <sstream>

#include "Lab03.h"

int main()
{
	float totalTicketSales = 0;

	std::cout << "Welcome to Fun Park Menu System !!";

	for (int day = 1; day <= 3; ++day)
	{
		int children = 0;
		int adults = 0;
		int seniors = 0;
		int vips = 0;

		std::cout << "\n\nStarting Day " << day << "\n";

		bool finishedDay = false;
		while (!finishedDay)
		{
			char userInput;
			GetValidInput(userInput, "Enter (C)hild, (A)dult, (S)enior, (V)IP, (Q)uit >> ", "CASVQ");

			switch (userInput)
			{
				case 'C':
				{
					children += GetValidNumber("How many children? ");
					break;
				}
				case 'A':
				{
					adults += GetValidNumber("How many adults? ");
					break;
				}
				case 'S':
				{
					seniors += GetValidNumber("How many seniors? ");
					break;
				}
				case 'V':
				{
					vips += GetValidNumber("How many vips? ");
					break;
				}
				default:
				{
					finishedDay = true;
					break;
				}
			}
		}

		float childTotal = children * CHILD_PRICE;
		float adultTotal = adults * ADULT_PRICE;
		float seniorTotal = seniors * SENIOR_PRICE;
		float vipTotal = vips * VIP_PRICE;
		float totalDay = childTotal + adultTotal + seniorTotal + vipTotal;
		totalTicketSales += totalDay;

		std::cout << "\nDay " << day;
		std::cout << "\n\tChild " << children << " @ " << CHILD_PRICE << " = " << childTotal;
		std::cout << "\n\tAdult " << adults << " @ " << ADULT_PRICE << " = " << adultTotal;
		std::cout << "\n\tSenior " << seniors << " @ " << SENIOR_PRICE << " = " << seniorTotal;
		std::cout << "\n\tVIP " << vips << " @ " << VIP_PRICE << " = " << vipTotal;
		std::cout << "\n\n\tTotal = " << totalDay;
	}

	std::cout << "\n\nThe total for all days is " << totalTicketSales << std::endl;

	return 0;
}

int GetValidNumber(const std::string &prompt)
{
	int validNumber;

	while (true)
	{
		std::cout << "\n" << prompt;

		std::string userInputString;
		std::getline(std::cin, userInputString);

		if ((std::stringstream(userInputString) >> validNumber).fail())
		{
			std::cout << "Please enter a valid number." << std::endl;
		}
		else
		{
			if (validNumber < 0)
			{
				std::cout << "Please enter a positive number." << std::endl;
			}
			else
			{
				return validNumber;
			}
		}
	}
}

void GetValidInput(char &userInput, const std::string &prompt, const std::string &validInputs)
{
	bool invalidInput = true;

	while (invalidInput)
	{
		std::cout << "\n" << prompt;

		std::cin >> userInput;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		userInput = toupper(userInput);

		invalidInput = validInputs.find(userInput) == std::string::npos;

		if (invalidInput)
		{
			std::cout << "You must enter ";
			for (unsigned int i = 0; i < validInputs.size() - 1; ++i)
			{
				if (i > 0)
				{
					std::cout << ", ";
				}
				std::cout << validInputs.at(i);
			}
			std::cout << " or " << validInputs.at(validInputs.size() - 1) << ".\n";
		}
	}
}