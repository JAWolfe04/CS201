//-----------------------------------------------------------------------------
// Jonathan Wolfe
// Email: jawhf4@mail.umkc
// Due: 2/14/19
// CS201L Lab 04
//-----------------------------------------------------------------------------

#pragma once
#include <string>

//Adds the amount to the account
void Deposit(float& account, float amount);

//Continuously prompts the user with the main menu until the user
//enters either D, W, L or Q and returns the entry
char MainMenu();

//Continuously prompts the user for a number greater than 0
float GetValue(std::string prompt);

//Continuously prompts the user for a number greater than 0 and
// less than or equal to the limit
float GetValue(std::string prompt, float limit);

//Returns an interest rate based on the credit score 
float GetInterestRate(int creditScore);

//Reduces the amount from the account
void Withdraw(float& account, float withdraw);

//Continuously prompts the user for a month range only accepting
//numbers, 12, 24, 36 or 60 then returns the entry
int GetLoanMonths();

//Continuously prompts the user for a number from 300 to 850 inclusive
//and returns the entry
int GetCreditRating();

//Returns the loan amount from the principal, interest rate and months and
//prints the info to the screen, changed from lab instructions because
//printing from main was needless
void CalculateLoanAmount(float principal, float interestRate, int months);

//Prints the balance to the screen
void OutputAccount(float balance);