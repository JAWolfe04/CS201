//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 2/7/2019
//-----------------------------------------------------------------------------

#pragma once

const float CHILD_PRICE = 10.95f;
const float ADULT_PRICE = 19.99f;
const float SENIOR_PRICE = 18.99f;
const float VIP_PRICE = 7.99f;

// Prompts user for input and sets userInput to a valid entry from the string of valid inputs, 
// continues prompting until input is valid
void GetValidInput(char &userInput, const std::string &prompt, const std::string &validInputs);

//Prompts the user from prompt and returns a positive number, continues prompting until input is valid
int GetValidNumber(const std::string &prompt);