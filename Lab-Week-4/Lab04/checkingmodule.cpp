//-----------------------------------------------------------------------------
// Jonathan Wolfe
// Email: jawhf4@mail.umkc
// Due: 2/14/19
// CS201L Lab 04
//-----------------------------------------------------------------------------

#include "checkingmodule.h"
#include <iostream>

void Deposit(float& account, float amount)
{
	account += amount;
}

void Withdraw(float& account, float withdraw)
{
	account -= withdraw;
}

char MainMenu()
{
	char input;
	std::string validOptions = "DWLQ";

	while (true)
	{
		std::cout << "Main Menu (Enter one of the following)\n\t(D)eposit, (W)ithdrawal, (L)oan or (Q)uit ==> ";

		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(256, '\n');

		input = toupper(input);

		if (validOptions.find(input) == std::string::npos)
		{
			std::cout << "Invalid entry: Must be D, d, W, w, L, l, Q or q\n\n";
		}
		else
		{
			return input;
		}
	}
}

float GetValue(std::string prompt)
{
	float amount;

	while (true)
	{
		std::cout << prompt;
		bool invalidEntry = (std::cin >> amount).fail();
		std::cin.clear();
		std::cin.ignore(256, '\n');

		if (!invalidEntry)
		{
			if (amount > 0)
			{
				return amount;
			}
			else
			{
				std::cout << "Invalid entry: Must more than 0\n";
			}
		}
		else
		{
			std::cout << "Invalid entry: Must be a number\n";
		}
	}
}

float GetValue(std::string prompt, float limit)
{
	while (true)
	{
		float amount = GetValue(prompt);

		if (amount <= limit)
		{
			return amount;
		}
		else
		{
			std::cout << "Invalid entry: Cannot be more than " << limit << '\n';
		}
	}
}

float GetInterestRate(int creditScore)
{
	if (creditScore <= 500)
	{
		return 0.05f;
	}
	else if (creditScore > 500 && creditScore <= 700)
	{
		return 0.03f;
	}
	else
	{
		return 0.01f;
	}
}

int GetLoanMonths()
{
	int months;

	while (true)
	{
		std::cout << "\nHow many months for the loan? 12, 24, 36, or 60  ==> ";
		bool invalidEntry = (std::cin >> months).fail();
		std::cin.clear();
		std::cin.ignore(256, '\n');

		if (!invalidEntry)
		{
			if (months == 12 || months == 24 || months == 36 || months == 60)
			{
				return months;
			}
			else
			{
				std::cout << "Invalid entry: Must be 12, 24, 36 or 60\n";
			}
		}
		else
		{
			std::cout << "Invalid entry: Must be a number.\n";
		}
	}
}

int GetCreditRating()
{
	int rating;

	while (true)
	{
		std::cout << "\nWhat is your credit rating? [300, 850]  ==> ";
		bool invalidEntry = (std::cin >> rating).fail();
		std::cin.clear();
		std::cin.ignore(256, '\n');

		if (!invalidEntry)
		{
			if (rating >= 300 && rating <= 850)
			{
				return rating;
			}
			else
			{
				std::cout << "Invalid entry: Must be a value from 300 - 850 inclusive\n";
			}
		}
		else
		{
			std::cout << "Invalid entry: Must be a number.\n";
		}
	}
}

void CalculateLoanAmount(float principal, float interestRate, int months)
{
	float loanAmount = principal * std::pow(1 + (interestRate / 12), months / 12);

	std::cout << "\nInterest Rate: " << interestRate << '\n';
	std::cout << "Principal: " << principal << '\n';
	std::cout << "Your total loan amount is " << loanAmount << "\n\n";
}

void OutputAccount(float balance)
{
	std::cout << "\nSummary of Account\n\tAmount $" << balance << "\n\n\n";
}