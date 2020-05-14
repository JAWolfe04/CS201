//-----------------------------------------------------------------------------
// Jonathan Wolfe
// Email: jawhf4@mail.umkc
// Due: 2/14/19
// CS201L Lab 04
//-----------------------------------------------------------------------------

#include "checkingmodule.h"

int main() {
	float accountValue = 0.0f;
	bool running = true;

	while (running)
	{
		char userChoice = MainMenu();
		switch (userChoice)
		{
			case 'D':
			{
				Deposit(accountValue, GetValue("\nHow much do you want to deposit?  ==>  "));
				OutputAccount(accountValue);
				break;
			}
			case 'W':
			{
				Withdraw(accountValue, GetValue("\nHow much do you want to withdraw  ==> ", accountValue));
				OutputAccount(accountValue);
				break;
			}
			case 'L':
			{
				float interestRate = GetInterestRate(GetCreditRating());

				int months = GetLoanMonths();

				float principal = GetValue("\nHow much do you want to borrow? ==> ");

				CalculateLoanAmount(principal, interestRate, months);
				break;
			}
			case 'Q':
			{
				running = false;
				break;
			}
		}
	}

	return 0;
}